#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  int ans=0;
  bool flag=false;
  for(int i=0;i<N-1;i++){
    if(a.at(i)==a.at(i+1)){
      if(flag){
        flag=false;
      }else{
        ans++;
        flag=true;
      }
    }else{
      flag=false;
    }
  }
  cout<<ans<<endl;
}
