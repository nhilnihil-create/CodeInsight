#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<v_char > v2_char;
typedef std::vector<double> v_double;
typedef std::vector<v_double > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<v_int > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<v_ll > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<v_string > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<v_bool > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std; 

int n, m, q;
v2_int Sum;

int main(void)
{
    int h, w;
    cin >> h >> w;

    v2_int a(h, v_int(w));
    
    irep(i, h) {
        irep(j, w) {
            cin >> a[i][j];
        }
    }
    
    v_int x, y, x2, y2;
    int ans = 0;
    irep(i, h-1) {
        irep(j, w) {
            if(a[i][j]%2 != 0) {
                ans++; 
                a[i+1][j]++;
                x.push_back(i+1);
                y.push_back(j+1);
                x2.push_back(i+2);
                y2.push_back(j+1);
            }
        }
    }

    irep(j, w-1) {
        if(a[h-1][j] % 2 != 0) {
            ans++;
            a[h-1][j+1]++;
            x.push_back(h);
            y.push_back(j+1);
            x2.push_back(h);
            y2.push_back(j+2);
        }
    }
    
    printf("%d\n", ans);
    irep(i, ans) {
        printf("%d %d %d %d\n", x[i], y[i], x2[i], y2[i]);
    }

    return 0;
}
/** tcoder **/
