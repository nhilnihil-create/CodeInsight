#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   set<string>st;
   string s; cin >> s;
   int k; cin >> k;
   rep(i,s.size()){
      rep(j,s.size()-i){
         if (j == 5)break;
         st.insert(s.substr(i,j+1));
      }
   }
   set<string>::iterator itr = st.begin();
   rep(i,k-1)itr++;
   cout << *itr << endl;
}