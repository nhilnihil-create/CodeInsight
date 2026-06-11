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
typedef std::vector<std::vector<char> > v2_char;
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

int n;
v_int l;
int A, B, C;
int ans = INF;
int cnt = 0;

int solve(v_int &v)
{
    int la = 0, lb = 0, lc = 0;
    int la_cnt = 0, lb_cnt = 0, lc_cnt = 0;
    int mp = 0;
    irep(i, n) {
        if(v[i] == 0) { la += l[i]; la_cnt++; }
        if(v[i] == 1) { lb += l[i]; lb_cnt++; }
        if(v[i] == 2) { lc += l[i]; lc_cnt++; }
    }
    mp = abs(la-A) + abs(lb-B) + abs(lc-C);
    mp += 10 * ((la_cnt-1) + (lb_cnt-1) + (lc_cnt-1));
    if(la_cnt == 0 || lb_cnt == 0 || lc_cnt == 0) {
        return INF;
    } else {
        return mp;
    }
}

void dfs(int i, v_int &v)
{
    if(i == n) {
        ans = min(ans, solve(v));
        return ;
    }
    v[i] = 0;
    dfs(i+1, v);
    v[i] = 1;
    dfs(i+1, v);
    v[i] = 2;
    dfs(i+1, v);
    v[i] = 3;
    dfs(i+1, v);
    return; 
}

int main(void)
{
    cin >> n >> A >> B >> C;
    
    l.resize(n);
    irep(i, n) {
        cin >> l[i];
    }

    v_int v(n);
    dfs(0, v);
    cout << ans << endl;
    return 0;
}
/** atcoder **/
