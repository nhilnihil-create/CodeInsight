#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define x   first
#define Y   second

const int   N   = 2e5 + 5;

typedef pair<int,int>   ii;
typedef vector<int>     vi;

int a[N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    int k;  cin >> k;
    int q;  cin >> q;

    vector<int> val;

    for(int i = 1 ; i <= n ; ++i)   {
        cin >> a[i];
        val.pb(a[i]);
    }
    sort(all(val));
    val.erase(unique(all(val)),val.end());

    int ans = 1e9;

    for(int x : val)    {
        vector<vi>  vec;
        vector<int> cur;

        for(int i = 1 ; i <= n ; ++i)   {
            if (a[i] < x)   {
                if (cur.size()) {
                    vec.pb(cur);
                    cur.clear();
                }
                continue;
            }
            cur.pb(a[i]);
        }
        if (cur.size())
            vec.pb(cur);
        
        vector<int> nvec;

        for(vi  V : vec)    {
            sort(all(V));

            for(int i = 0 ; i <= sz(V) - k ; ++i)
                nvec.pb(V[i]);
        }
        sort(all(nvec));

        if (sz(nvec) < q)
            continue;

        if (ans > nvec[q - 1] - x)
            ans = nvec[q - 1] - x;
    }
    cout << ans << endl;
}