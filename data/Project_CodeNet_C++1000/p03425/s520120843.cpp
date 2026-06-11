#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<ll> begin(5,0);

    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        switch (s[0])
        {
        case 'M':
            begin[0]++;
            break;
        case 'A':
            begin[1]++;
            break;
        case 'R':
            begin[2]++;
            break;
        case 'C':
            begin[3]++;
            break;
        case 'H':
            begin[4]++;
            break;
        default:
            break;
        }
    }

    ll ans = 0;
    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<5; k++) {
                ans += begin[i] * begin[j] * begin[k];
            }
        }
    }
    cout << ans << endl;
}