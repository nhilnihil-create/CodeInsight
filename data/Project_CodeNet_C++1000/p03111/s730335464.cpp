#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

int n, A, B, C;
vector<int> v;

int dfs(int trenutni, int a, int b, int c)
{
    if(trenutni == n)
    {
        if(min(a,min(b,c)) <= 0)
        {
            return 1e9;
        }
        else
        {
            return abs(a-A) + abs(b-B) + abs(c-C);
        }
    }

    int minimalno = 1e9;
    minimalno = min(minimalno, dfs(trenutni+1, a, b, c));
    minimalno = min(minimalno, dfs(trenutni+1, a+v[trenutni], b, c) + 10);
    minimalno = min(minimalno, dfs(trenutni+1, a, b + v[trenutni], c) + 10);
    minimalno = min(minimalno, dfs(trenutni+1, a, b, c + v[trenutni]) + 10);
    return minimalno;
}

int main()
{
    cin >> n >> A >> B >> C;

    v.resize(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << dfs(0, 0, 0, 0)-30 << '\n';

    return 0;
}
