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
    int n, c;
    cin >> n >> c;

    //map<pii, int> d, color;
    v2_int d(c+1, v_int(c+1)), color(n, v_int(n));

    irep(i, c) {
        irep(j, c) {
            cin >> d[i+1][j+1];
        }
    }   

    irep(i, n) {
        irep(j, n) {
            cin >> color[i][j];
        }
    }
    
    v2_int cost(3, v_int(c, 0)); 

    irep2(k, 1, c) {
        irep(i, n) {
            irep(j, n) {
                int mod3 = (i+1+j+1)%3;
                int org_col = color[i][j];
                if(org_col != k) {
                    cost[mod3][k-1] += d[org_col][k]; 
                }
            }
        }
    }
#if 0
    irep(i, 3) {
        irep(j, c) {
            printf("%d,", cost[i][j]);
        } printf("\n");
    }
#endif
    int ans = INF;
    irep(i, c) {
        irep(j, c) {
            irep(k, c) {
                if(i == j || i == k || j == k) { continue; }
                ans = min(ans, cost[0][i]+cost[1][j]+cost[2][k]); 
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/** atcoder **/
