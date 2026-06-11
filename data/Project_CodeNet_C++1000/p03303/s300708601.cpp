#include<bits/stdc++.h>
#define F first
#define S second
#define endl '\n'
#define MP make_pair
#define pb push_back

using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> i_P;
typedef long long LL;

static const int INF = INT_MAX;
static const LL L_INF = LLONG_MAX;
static const int MOD = (1000000000 + 7);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int w;
    cin >> w;

    for( int i = 0; i < s.size(); ++i ) {
        if( !( i % w ) ) cout << s[i];
    }
    cout << endl;
    return 0;
}

