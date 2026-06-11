#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int K;
    cin >> K;

    int n = s.size();

    vector<string> vec;
    
    rep(i, 1, min(n, 5) + 1) {
        rep (j, 0, n - i + 1) {
            vec.push_back(s.substr(j, i));
        }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << vec[K - 1] << endl;
    return 0;
}