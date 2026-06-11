#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
   string s;
   cin >> s;
   string target = "keyence";
   int n = s.size();
    rep(i,n){
      for(int j=0; j<n; j++){
          string a = s;
          a.erase(i,j);
          if(a == target){
              cout << "YES" <<endl;
              return 0;
          }
      }
  }
   cout << "NO" <<endl;
}