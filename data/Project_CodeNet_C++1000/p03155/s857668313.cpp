#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
using pp=pair<int,pair<int,int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N,H,W;
  cin>>N>>H>>W;
  cout<<max(N-H+1,0)*max(N-W+1,0)<<endl;
}
