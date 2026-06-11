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

void make_comb(int a, int b, int c)
{
#if 1
    for(int ai = 0; ai < (1<<n); ai++) {
        int a_cnt = 0, la = 0;
        v_bool a_use(n, false);
        v_int b_vec;
        int mp = 0;

        for(int i = 0; i < n; i++) {
            if(ai & (1<<i)) {
                a_cnt++;
                a_use[i] = true;
                la += l[i];
            } else {
                b_vec.push_back(i);
            }
        }

        if(a_cnt != a) { continue; }
        mp += (a_cnt-1) * 10;     
        mp += abs(la - A);            

        for(int bi = 0; bi < (1<<b_vec.size()); bi++) {
            int b_cnt = 0, lb = 0;
            v_bool b_use(b_vec.size(), false);
            v_int c_vec;
            int mp_ab = mp;

            for(int i = 0; i < b_vec.size(); i++) {
                if(bi & (1<<i)) {
                    b_cnt++;
                    b_use[i] = true;
                    lb += l[b_vec[i]];
                } else {
                    c_vec.push_back(b_vec[i]);
                }
            }
            if(b_cnt != b) { continue; }
            mp_ab += (b_cnt-1) * 10;     
            mp_ab += abs(lb - B);            

            for(int ci = 0; ci < (1<<c_vec.size()); ci++) {
                int c_cnt = 0, lc = 0;
                int mp_abc = mp_ab;
                for(int i = 0; i < c_vec.size(); i++) {
                    if(ci & (1<<i)) {
                        c_cnt++;
                        lc += l[c_vec[i]];
                    }
                }
                if(c_cnt != c) { continue; }
                mp_abc += (c_cnt-1) * 10;     
                mp_abc += abs(lc - C);            
                ans = min(ans, mp_abc);
            }
        }
    }
#endif
}

int main(void)
{
    cin >> n >> A >> B >> C;
    
    l.resize(n);
    irep(i, n) {
        cin >> l[i];
    }

    irep2(i, 1, n) {
        irep2(j, 1, n-i-1) {
            irep2(k, 1, n-(i+j)) {
                //printf("%d,%d,%d\n", i, j, k);
                make_comb(i, j, k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/** atcoder **/
