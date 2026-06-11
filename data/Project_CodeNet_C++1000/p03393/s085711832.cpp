#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    vector<char> v(26);
    rep(i, 26){
        v[i] = 'a' + i;
    }

    rep(i, s.size()){
        auto result = find(all(v), s[i]);
        v.erase(result);
    }

    if(s.size() == 26){
      for (int i = 24; i >= 0; i--) {
      if (s[i] < s[i + 1]) {
        for (int j = s.size() - 1; j > i; j--) {
          if (s[i] < s[j]) {
            swap(s[i], s[j]);
            cout << s.substr(0, i + 1) << endl;
            return 0;
          }
        }
      }
      }
    }else{
        s.push_back(v[0]);
        cout << s << endl;
    }

    return 0;
}
