#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 1e9+7
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;
//=========================================

int parent[N], sz[N];

void make_set(int x){
    parent[x] = x;
    sz[x] = 1;
}

int find_set(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void merge(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        make_set(i);

    vpii a(m);
    vector<int> ans(m + 1);

    for(int i = 0; i < m; ++i){
        cin >> a[i].first >> a[i].second;
    }

    ans[m] = (n * (n - 1)) / 2; // when all bridges are removed

    // start from the last bridge removed to the first bridge removed
    // and one by one add the bridge and reduce the count of inconvenience
    for(int i = m - 1; i >= 0; --i){
        int x = a[i].first;
        int y = a[i].second;

        // already in the same set then continue
        if(find_set(x) == find_set(y)){
            ans[i] = ans[i + 1];
            continue;
        }

        int sz_x = sz[find_set(x)];
        int sz_y = sz[find_set(y)];

        // merge the two disjoint sets
        merge(x, y);

        // by merging the two components, we reduce the pair
        // of cities we can reach from the total inconveniences.
        ans[i] = max(ans[i + 1] - (sz_x * sz_y), 0LL);
    }

    for(int i = 1; i <= m; ++i)
        cout << ans[i] << "\n";
    //cout << endl;

    return 0;
}
