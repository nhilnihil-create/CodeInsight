#include <bits/stdc++.h>

using namespace std;

#define ll long long
constexpr ll inf = 1e9+7;

pair<ll, string> find(string S, string sub, ll k, ll K) {
    string s = sub + "a";
    for (ll i = 0; i < 26; i++) {
        s[s.length()-1] = 'a' + i;
        if (S.find(s) != string::npos) {
            k++;
            if (k == K) return make_pair(K, s);
            else {
                auto result = find(S, s, k, K);
                if (result.first == K) return result;
                else k = result.first;
            }
        }
    }
    return make_pair(k, string(""));
}

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    ll K;
    cin>>S>>K;

    auto result = find(S, "", 0, K);
    cout<<result.second<<endl;

    return 0;
}