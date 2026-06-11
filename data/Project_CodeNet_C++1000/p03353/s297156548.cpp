#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef vector<int,vector<int>> vec;
typedef pair<string,int> P;
#define REP(i,j,n) for (int i=j;i<(n);i++)
#define RREP(i,n,j) for (int i = n; j<i;i--)
#define print(out) cout<< out  << "\n";
#define all(vec) vec.begin(),vec.end()
#define mod 1000000007
const int INF = 1e9;

int main(){
  string S;int K;cin>>S>>K;
  set<string> st;
  REP(i,0,S.size()){
    REP(j,1,min(6,(int)S.size()+1)){
      string substr=S.substr(i,j);
      st.insert(substr);
    }
  }
  vector<string> vec(st.begin(),st.end());
  print(vec[K-1])
}
