#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int  i = (0; i < n; i++)
#define irrep2(i,a,n) for(int i = (a); i <= (int)(n); i++)

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
    int n; 
    cin >> n;

    v_int t(n, 0), v(n, 0);
    v_int sum_t(n, 0);

    irep(i, n) { cin >> t[i]; }
    irep(i, n) { cin >> v[i]; }
    
    int T = 0;
    irep(i, n) { T += t[i]; }

    v_double v_max(2*T+1);
    int time = 0;
    irep(i, n) {
        irep(j, t[i]-1) {
            v_max[time+1] = v[i];
            v_max[time+2] = v[i];
            time += 2;
        }
        v_max[time+1] = v[i];
        v_max[time+2] = min(v[i], v[i+1]);
        time += 2;
    }
    
    v_max[2*T] = 0;
    v_max[0] = 0;

    irep2(i, 1, 2*T) {
        v_max[i] = min(v_max[i], v_max[i-1] + 0.5);
    }

    for(int i = 2*T-1; i >= 0; i--) {
        v_max[i] = min(v_max[i], v_max[i+1] + 0.5);
    }
    
    double ans = 0.0;
    irep2(i, 1, 2*T) {
        ans += (v_max[i] + v_max[i-1]) * 0.25;
        //cout << ans << "," << i << endl;
    }

    printf("%.7f\n", ans);
    return 0;
}
/** atcoder **/
