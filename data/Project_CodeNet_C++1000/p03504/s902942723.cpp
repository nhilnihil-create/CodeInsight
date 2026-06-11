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
    
    v2_int prog(c, v_int(200000, 0));

    irep(i, n) {
        int s, t, ch;
        cin >> s >> t >> ch;
        int time = (s-1) * 2;
        irep2(j, s, t) {
            if(j != s) {
                prog[ch-1][time] = 1;
                prog[ch-1][time+1] = 1;
            } else { 
                prog[ch-1][time+1] = 1;
            }
            time += 2;
        }
    }

    v_int tv(200000, 0);

    irep(i, c) {
        irep(j, 200000) {
            tv[j] += prog[i][j];
        } 
    }

    int ans = -1;
    irep(j, 200000) {
        ans = max(tv[j], ans);
    } 
    cout << ans << endl;
    return 0;
}
/** atcoder **/
