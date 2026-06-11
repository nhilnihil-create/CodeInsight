#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int BIG = 2e9 + 55;

int n;
string s;
map<pair<string, string>, ll> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cin >> s;

    for(int bitmask0 = 0; bitmask0 < (1 << n); bitmask0++){
        string a = "", b = "";
        for(int i = 0; i < n; i++){
            if(bitmask0 & (1 << i)){
                a.push_back(s[i]);
            } else {
                b.push_back(s[i]);
            }
        }

        cnt[make_pair(a, b)]++;
    }

    ll fRes = 0;
    for(int bitmask = 0; bitmask < (1 << n); bitmask++){
        string a = "", b = "";
        for(int i = n - 1; i >= 0; i--){
            if(bitmask & (1 << i)){
                a.push_back(s[n + i]);
            } else {
                b.push_back(s[n + i]);
            }
        }

        fRes += cnt[make_pair(a, b)];
    }

    cout << fRes << '\n';

    return 0;
}