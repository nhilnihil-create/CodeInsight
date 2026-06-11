#include "bits/stdc++.h"

using namespace std;

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define int long long
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define INF LLONG_MAX
#define EPS 1e-9
#define all(v) (v).begin(),(v).end()
#define sq(x) ((x)*(x))
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)


#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
typedef long double dbl;
bool codejam = 0;

const int MOD = 1000*1000*1000 + 7;
const int NMAX = 1000*1000 + 11;

int arr[305];
int n;
string s,str;
char ch;
vector<int> v;
double p[303][303][303];
double ev[303][303][303];
int cnt[4];

void solve()
{
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1;

    for(int c = n; c >= 0; c--){
        for(int b = n; b >= 0; b--){
            for(int a = n; a >= 0; a--){
                if(a+b+c > n) continue;
                if(a + b + c == 0) continue;

                double x = (1.0*(n - (a+b+c)))/n;
                double p_waste = (x/(1-x)) + 1;
                double p_go;

                ev[a][b][c] += p[a][b][c]*p_waste;

                if(c > 0){
                    p_go = (double)(c)/(a+b+c);
                    p[a][b+1][c-1] += p[a][b][c]*p_go;
                    ev[a][b+1][c-1] += ev[a][b][c]*p_go;
                }
                if(b > 0){
                    p_go = (double)(b)/(a+b+c);
                    p[a+1][b-1][c] += p[a][b][c]*p_go;
                    ev[a+1][b-1][c] += ev[a][b][c]*p_go;
                }
                if(a > 0){
                    p_go = (double)(a)/(a+b+c);
                    p[a-1][b][c] += p[a][b][c]*p_go;
                    ev[a-1][b][c] += ev[a][b][c]*p_go;
                }

            }
        }
    }
    cout<<fixed<<setprecision(12)<<ev[0][0][0]<<"\n";
}

int32_t main(){ fio;
    int t = 1;
    int cs = 1;
    // cin>>t;
    while(t--){
        if(codejam){
            cout<<"Case #"<<cs<<": ";
        }
        cs++;
        solve();
        cout<<"\n";
    }
}