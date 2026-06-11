#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef vector<int,vector<int>> vec;
typedef pair<int,int> P;
#define REP(i,j,n) for (int i=j;i<(n);i++)
#define RREP(i,n) for (int i = n; 0<i;i--)
#define print(out) cout<< out  << "\n";
#define all(vec) vec.begin(),vec.end()
#define mod 1000000007
const int INF = 1e9;

int main(){
  ll N,K;cin>>N>>K;
  ll answer = 0;
 
  if (K % 2 == 0) {
    ll c1 = N / K;
    ll c2 = N / (K / 2) - c1;
    answer = c1*c1*c1+c2*c2*c2;
  } else {
    ll c = N / K;
    answer = c*c*c;
  } 
  print(answer)

  return 0;
}
