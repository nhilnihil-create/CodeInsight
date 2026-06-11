#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    string prefix = "MARCH";
    vector<ll> cnt('Z' - 'A');
    rep(i, n) {
        if (prefix.find(S[i][0]) != std::string::npos) {
            cnt[S[i][0] - 'A']++;
        }
    }

    ll sum = 0;
    for (int i = 0; i < prefix.size() - 2; i++) {
        for (int j = i + 1; j < prefix.size() - 1; j++) {
            for (int k = j + 1; k < prefix.size(); k++) {
                sum += cnt[prefix[i] - 'A'] * cnt[prefix[j] - 'A'] * cnt[prefix[k] - 'A'];
            }
        }
    }

    put(sum);

    return 0;
}