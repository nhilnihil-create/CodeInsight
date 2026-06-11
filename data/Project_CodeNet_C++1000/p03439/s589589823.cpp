#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    pair<int, int> T=make_pair(0, N);
    cout << 0 << endl;
    string s;
    cin >> s;
    if (s == "Vacant") return 0;

    map<int, string> mp;
    mp[0] = s;
    mp[N] = s;

    for (int i = 0; i < 19; i++) {
        int q = (T.second-T.first)/2 + T.first;
        cout << q << endl;
        string s;
        cin >> s;
        if (s == "Vacant") return 0;

        mp[q] = s;
        if ((q-T.first)%2) {
            if (s==mp[T.first]) T.second=q;
            else T.first=q;
        } else {
            if (s!=mp[T.first]) T.second=q;
            else T.first = q;
        } 
    }
}
