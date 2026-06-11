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
  int N;cin>>N;
  vector<int> vec(N);
  REP(i,0,N)cin>>vec[i];
  int max_m=abs(vec[0]-0)+abs(0-vec[N-1]);
  REP(i,0,N-1){
    max_m+=abs(vec[i+1]-vec[i]);
  }
  //print(max_m)

  vector<int> ans(N,max_m);
  ans[0]-=abs(vec[0]-0)+abs(vec[1]-vec[0])-abs(vec[1]-0);
  REP(i,1,N-1){
    ans[i]-=abs(vec[i]-vec[i-1])+abs(vec[i+1]-vec[i])-abs(vec[i+1]-vec[i-1]);
  }
  ans[N-1]-=abs(vec[N-1]-vec[N-2])+abs(0-vec[N-1])-abs(0-vec[N-2]);
  REP(i,0,N){
    print((ans[i]))
  }

}
