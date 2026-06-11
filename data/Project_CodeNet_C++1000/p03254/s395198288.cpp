#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;
int main(){
  int N;
  int64_t x;
  cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  int64_t sum=0;
  for(int i=0;i<N;i++){
    sum+=a.at(i);
  }
  int count=0;
  if(x<sum){
    int i=0;
    while(x-a.at(i)>=0){
     x-=a.at(i);
     i++;
     count++;
    }
    cout<<count<<endl;
  }
  else if(x==sum){cout<<N<<endl;}
  else{cout<<N-1<<endl;}
  return 0;
}