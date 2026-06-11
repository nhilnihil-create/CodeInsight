#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = (a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (a); i <= (long long)(n); i++)

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
    int n, K;
    cin >> n >> K;

    v_ll x(n), y(n);
    
    irep(i, n) {
        cin >> x[i] >> y[i];
    }

    ll ans = LINF*4 + 2;

    irep(i, n) {
        irep(j, n) {
            irep(k, n) {
                irep(l, n) {
                    ll x1 = x[i], x2 = x[j];
                    ll y1 = y[k], y2 = y[l];
                    int cnt = 0;
                    if(x2 > x1 && y2 > y1) {
                        irep(a, n) {
                            bool x_lim = false, y_lim = false;
                            ll xn = x[a], yn = y[a];

                            if(x2 >= xn && xn >= x1) { x_lim = true; }
                            if(y2 >= yn && yn >= y1) { y_lim = true; }
                            if(x_lim & y_lim) {
                                cnt++;
                            }
                        }
                        ll s = (x2 - x1) * (y2 - y1);
                        if(cnt >= K) {
                            ans = min(ans, s);
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
/** atcoder **/
