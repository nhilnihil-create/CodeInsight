#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef vector<int,vector<int>> vec;
typedef pair<int,int> P;
#define REP(i,j,n) for (int i=j;i<(n);i++)
#define RREP(i,n,j) for (int i = n; j<i;i--)
#define print(out) cout<< out  << "\n";
#define all(vec) vec.begin(),vec.end()
#define mod 1000000007
const int INF = 1e9;

int main(){
  ll N,M;cin>>N>>M;
  if(N==1&&M==1){
    print(1);
    return 0;
  }
  else if(N==1){
    print(max(M-2,0LL))
    return 0;
  }
  else if(M==1){
    print(max(N-2,0LL))
    return 0;
  }
  print(max((N-2)*(M-2),0LL))
  return 0;
}
