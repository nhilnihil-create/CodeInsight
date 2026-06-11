#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,s,e) for(int i=s;i<=e;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX (int)1e9 + 99
#define maxof(a,b,c) max(a,max(b,c))
#define minof(a,b,c) min(a,min(b,c))
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pa pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define bitcnt(x) __builtin_popcount(x)
#define gcd(a,b) __gcd(a,b)
#define all(x) (x).begin(),(x).end()
#define ts(x) to_string(x)
#define set0(x) memset(x, 0, sizeof(x))
const double pi = 3.14159265358979323846;
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is;}
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) {if (!v.empty()) {os << v.front();for (int i = 1; i < v.size(); ++i) os << ' ' << v[i];} return os;}
const int N=301;

double p[N][N][N];
double v[N][N][N];

void solve()
{
    int n;
    cin>>n;
    int x;
    vi cnt(4,0);
    rep(i,n)
    {
        cin>>x;
        cnt[x]++;
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1.0;
    for(int z = n; z>=0;z--)
    {
        for(int y= n; y>=0; y--)
        {
            for(int x = n; x>=0; x--)
            {
                if(x==0 && y==0 && z==0)
                    continue;

                if(x+y+z > n) 
                    continue;

                double p_zero = (double)(n-(x+y+z))/n;

                //no of events where we take to reach a valid choice 1 + 1*p_zero+ 1*p_zero^2+...
                double event_number = 1/(1-p_zero);

                v[x][y][z] += event_number * p[x][y][z];


                //if we remove a sushi from a plate with 1 sushi 
                if(x)
                {
                    double p_this = (double)x/(x+y+z);
                    p[x-1][y][z] += p[x][y][z] * p_this;
                    v[x-1][y][z] += v[x][y][z] * p_this;
                }

                //if we remove a sushi from a plate with 2 sushi...no of 2 sushi plates decreases by 1, no of 1 sushi plates increases by 1
                if(y)
                {
                    double p_this = (double)y/(x+y+z);
                    p[x+1][y-1][z] += p[x][y][z] * p_this;
                    v[x+1][y-1][z] += v[x][y][z] * p_this; 
                }

                //if we remove a sushi from a plate with 3 sushi...no of 3 sushi plates decreases by 1, no of 2 sushi plates increases by 1
                if(z)
                {
                    double p_this = (double)z/(x+y+z);
                    p[x][y+1][z-1] += p[x][y][z] * p_this;
                    v[x][y+1][z-1] += v[x][y][z] * p_this; 
                }
            }
        }
    }


    cout<<fixed<<setprecision(10)<<v[0][0][0];

}

int main()
{
    fastio;
    
    int t=1;
    
    rep(i,t)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}
