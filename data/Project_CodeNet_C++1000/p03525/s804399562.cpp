#include <bits/stdc++.h> 

using namespace std; 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>; 

#define INF INT_MAX;
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

int main(){
  int N;
  cin>>N;
  vector<int>D(N);
  for(int i=0;i<N;i++)cin>>D[i];
  map<int,int>m;
  m[0]++;
  for(int i=0;i<N;i++)m[D[i]]++;

  for(int i=0;i<=12;i++){
    if(i==0||i==12){
      if(m[i]>=2){
        cout<<0<<endl;
        return 0;
      }
    }
    else{
      if(m[i]>=3){
        cout<<0<<endl;
        return 0;
      }
    }
  }

  vector<int>bits;
  for(int b=0;b<pow(2,13);b++){
    bool ok=true;
    if(m[0]==1&&!(b&1))continue;
    if(m[12]==1&&!((b>>12)&1))continue;
    for(int i=1;i<=11;i++){
      if(m[i]==0){
        if((b>>i)&1){
          ok=false;
          break;
        }
      }
      else if(m[i]==2){
        if(!((b>>i)&1)){
          ok=false;
          break;
        }
      }
    }
    if(ok)bits.push_back(b);
  }

  int Max=0;
  for(auto it:bits){
    vector<int>a;
    int Min=INF;
    if(m[0])a.push_back(0);
    if(m[12])a.push_back(12);
    for(int i=1;i<=11;i++){
      if(m[i]==1){
        if((it>>i)&1)a.push_back(i);
        else a.push_back(24-i);
      }
      else if(m[i]==2){
        a.push_back(i);
        a.push_back(24-i);
      }
    }
    a.push_back(24);
    sort(rng(a));
    for(int i=0;i<a.size()-1;i++){
      Min=min(Min,a[i+1]-a[i]);
    }
    Max=max(Max,Min);
  }
  cout<<Max<<endl;
  return 0;
}
