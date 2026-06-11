#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1000000009
#define LINF 1000000000000000009
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

int main(void)
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    
    int ans = 0;
    for(int i = 0; i * R <= N; i++) {
        int r = i * R;
        for(int j = 0; j * G <= N; j++) {
            int g = j * G;
            int b = N - (r+g);
            if(b % B != 0 || b < 0) { continue; }
            if(r+g+b == N) { ans++; }
        }
    }
    cout << ans << endl;
}
/** tcoder **/
