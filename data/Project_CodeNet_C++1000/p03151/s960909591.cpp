#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
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

const double PI = 3.14159265359;
const int INF = (int)1e9;
const ll LINF = 1e18;
const int IMOD = 1000000007;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

using namespace std; 

int main(void)
{
    int n;
    cin >> n;
    
    v_int a(n);
    ll suma = 0, sumb = 0, diff = 0;
    irep(i, n) { cin >> a[i]; suma += a[i]; }

    priority_queue<int> q;
    int ans = 0;

    irep(i, n) { 
        int b; cin >> b;
        sumb += b;
        if(b > a[i]) {
            diff += b-a[i];            
            ans++;
        } else {
            if(b != a[i]) {
                q.push(a[i]-b);
            }
        }
    }
    
    if(suma < sumb) { 
        cout << -1 << endl;
        return 0;
    }

    while(diff > 0) {
        int d = q.top(); q.pop();    
        if(diff <= d) {
            ans++;
            break;
        } else {
            diff -= d;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
/** atcoder **/

