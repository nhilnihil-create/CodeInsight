#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    ld res = 0.00;

    for(int i = 1; i <= n; ++i)
    {
        int tren = i;
        ld temp = 1.00 / n;
        while(tren < k)
        {
            tren<<=1;
            temp /= 2.00;
        }
        res += temp;
    }
    cout << fixed << setprecision(10) << res << '\n';
}
