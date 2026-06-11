#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  string S;
  cin>>S;
  int N=S.size();
  int i=0;
  ll ans=0;
  ll num=0;
  while(i<N){
    if(S.at(i)=='A'){
      num++;
      i++;
    }else if(i!=N-1){
      if(S.at(i)=='B'&&S.at(i+1)=='C'){
        ans+=num;
        i+=2;
      }else{
        i++;
        num=0;
      }
    }else{
      i++;
    }
  }
  cout<<ans<<endl;
}
