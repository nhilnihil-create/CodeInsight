#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>

#define PB push_back
#define MP make_pair
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define INF (1<<30)
#define LLINF (1<<60)
#define MOD 1000000007
#define REP(i, n) for(int i=0;i<n;i++)
using ll = long long;
using namespace std;

int main() {
    ll n, q;
    string s;
    cin >> n >> s >> q;
    for (ll i = 0; i < q; i++) {
        ll t;
        cin >> t;
        ll d = 0, m = 0, sum = 0, ans = 0;
        for (ll j = 0; j < n; j++) {
            if (j > t-1) {
                if (s[j - t] == 'D')d--, sum -= m;
                if (s[j - t] == 'M')m--;
            }
            if (s[j] == 'D')d++;
            if (s[j] == 'M')m++, sum += d;
            if (s[j] == 'C')ans += sum;
        }
        cout << ans << endl;
    }
    return 0;
}
