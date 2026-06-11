#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
    string s, t;
    cin >> s >> t;
    ll len_s = s.size();
    ll len_t = t.size();
    bool restore = false;
    for (int i = len_s - len_t; i >= 0; i--) {
      bool replace = true;
      for (int j = 0; j < len_t; j++) {
        if (s[i + j] != '?' && s[i + j] != t[j]) {
          replace = false;
          break;
        }
      }

      if(replace){
        restore = true;
        for (int j = 0; j < len_t; j++) {
          s[i + j] = t[j];
        }
        break;
      }
    }

    if(restore){
        for(int i = 0; i < len_s; i++){
            if(s[i]=='?'){
              cout << 'a';
            }
            else{
              cout << s[i];
            }
        }
    } else {
      cout << "UNRESTORABLE" << endl;
    }
    return 0;
}