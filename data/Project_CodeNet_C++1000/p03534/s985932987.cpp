#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    rep(i, s.size()){
        a += (s[i] == 'a');
        b += (s[i] == 'b');
        c += (s[i] == 'c');
    }

    int diff = max({a, b, c}) - min({a, b, c});
    if(diff > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}