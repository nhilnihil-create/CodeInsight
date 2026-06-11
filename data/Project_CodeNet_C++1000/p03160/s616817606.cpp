#include <bits/stdc++.h>
#define ll long long
#define mp(a, b) make_pair(a, b)
#define newline cout << endl;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(),v.end()
using namespace std;

template <typename S, typename T> ostream& operator<<(ostream& out, pair<S, T> const& p)
{
    out << '(' << p.ff << ", " << p.ss << ')';
    return out;
}

template <typename T> ostream& operator<<(ostream& out, vector<T> const& v)
{
    int l = v.size();
    for (int i = 0; i < l - 1; i++)
        out << v[i] << ' ';
    if (l > 0)
        out << v[l - 1];
    return out;
}

template <typename T> void trace(const char* name, T&& arg1) { cout << name << " : " << arg1 << endl; }

template <typename T, typename... Args> void trace(const char* names, T&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    trace(comma + 1, args...);
}

/*Input*/
const ll vsize = 1e6;
vector<ll> v(vsize), cost(vsize);
ll n;
/*Input*/

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    clock_t tStart = clock();
    int test;
    test = 1;
    /* cin >> test; */
    while (test--) {
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        cost[0] = 0;
        for(int i = 1; i < n; i++){
            if(i==1){
                cost[i] = abs(v[i-1] - v[i]);
                continue;
            }
            cost[i] = min( cost[i-1] + abs(v[i-1]-v[i]), cost[i-2] + abs(v[i-2] - v[i])  );
        }
        cout << cost[n-1] << "\n";
    }
#ifdef LOCAL_DEFINE
    printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}







