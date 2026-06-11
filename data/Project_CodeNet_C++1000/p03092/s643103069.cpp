#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define all(x)  x.begin(),x.end()
#define sz(x)   (int)x.size()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 5005;
const ll    inf = 1e18;

typedef pair<int,int>   ii;

int p[N];
ll  f[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    int A;  cin >> A;
    int B;  cin >> B;

    p[++n] = n;

    for(int i = 1 ; i <  n ; ++i)   cin >> p[i];
    for(int i = 1 ; i <= n ; ++i)   {
        f[i] = inf;
        int cnt = 0;

        for(int j = i - 1 ; j >= 0 ; --j)   {
            if (p[j] > p[i])
                cnt++;
            else    {
                ll  nxt = f[j] + 1ll * A * cnt + 1ll * B * (i - j - 1 - cnt);

                if (f[i] > nxt)
                    f[i] = nxt;
            }
        }
    }
    cout << f[n] << endl;
}