#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int i = (int)(n); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std; 

int main(void)
{
    int h, w, d;
    cin >> h >> w >> d;

    map<int, pii> mp;
    
    irep(i, h) {
        irep(j, w) {
            int a;
            cin >> a;
            mp[a] = pii(i,j);
        }
    }
    
    v_int dist(h*w, 0);

    for(int i = 1; i <= d; i++) {
        int sum = 0;
        for(int j = i; j <= h*w; j+=d) {
            sum += abs(mp[j].first - mp[j-d].first);
            sum += abs(mp[j].second - mp[j-d].second);
            dist[j] = sum;    
        }
    }

    int q; 
    cin >> q;
    v_int l(q), r(q);
    irep(i, q) {
        cin >> l[i] >> r[i];
    }

    v_int ans(q, 0);
    irep(i, q) {
        cout << dist[r[i]] - dist[l[i]] << endl;
        #if 0
        int a = l[i];
        while(a != r[i]) {
            int x = mp[a].first; 
            int y = mp[a].second; 
            a += d;
            int to_x = mp[a].first; 
            int to_y = mp[a].second; 

            ans[i] += abs(x-to_x) + abs(y-to_y);
        }
        #else 

        #endif
    }

    return 0;
}
/** atcoder **/
