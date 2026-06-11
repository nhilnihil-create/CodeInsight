#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
#define INF 1000000000000000000
#define MOD 1000000007

int main(){
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  ll ans=0;
  for(int i=0;R*i<=N;i++){
    for(int j=0;R*i+G*j<=N;j++){
      if((N-R*i-G*j)%B==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
