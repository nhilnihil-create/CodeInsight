#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  int N;
  cin>>N;
  vector<int>b(N),t(N);
  for(int i=0;i<N;i++){
    cin>>b[i];
  }
  t=b;
  vector<int>ans;
  for(int i=0;i<N;i++){//N回まわす
     int s=t.size(); 
     for(int j=s-1;j>=0;j--){
       if(t[j]==j+1){
        ans.push_back(t[j]);
        t.erase(t.begin()+j);
        break;
       }
    }
  }
  reverse(ans.begin(),ans.end());
  if(t.empty()){
    for(int i=0;i<N;i++){
      cout<<ans[i]<<endl;
    }
  }
  else{cout<<-1<<endl;}
  return 0;  
}