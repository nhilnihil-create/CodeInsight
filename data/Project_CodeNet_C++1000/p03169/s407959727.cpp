#include <bits/stdc++.h>
using namespace std;
#define ll long long                  // Short form for long long
#define ld long double                // Short form for long double
typedef pair<ll, ll> pii;              // Pair of long long
typedef vector<ll> vi;                // Vector of long long
typedef vector<vi> vvi;               // Vector of vector of long long
typedef vector<pii> vii;               // Vector of pairs
typedef vector<vii> vvii;             // Vector of vector of pairs
#define pq priority_queue             // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                      // For pairs
#define ss second                     // For pairs
#define pb push_back                  // Pushback to vector
#define mp make_pair                  // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end() // Mainly used by me in sorting

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
bool isPrime(ll n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false;   
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false;   
    return true; 
} 

ll mod = 1e9 + 7;
ll t=1;



vvi adj;
ll n,m,x,y,k;
// vi p,vis;
#define max 309

double p[max][max][max],ev[max][max][max];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin>>t;
    while(t--){
        cin>>n;
        vi cnt(4),arr(n);
        
        for(ll &x:arr){cin>>x; cnt[x]++;}
        
        p[cnt[1]][cnt[2]][cnt[3]]=1;
        
//        cout<<cnt[1]<<" "<<cnt[2]<<cnt[3]<<"\n";
        
        for(int c=n;c>=0;c--){
            for(int b=n;b>=0;b--){
                for(int a=n;a>=0;a--){
                    if(a+b+c>n || a+b+c==0)continue;
                    
                    double p_wasted = (double)(n-(a+b+c))/n;
                    double ev_wasted = p_wasted/(1-p_wasted);                    
                    
                    ev[a][b][c] += ev_wasted*p[a][b][c];
                    
                    if(a>0){
                    	double x =(double) (a)/(a+b+c);
						p[a-1][b][c] += (double) p[a][b][c]*x;
						ev[a-1][b][c] += ev[a][b][c]*x;
                		}
                    if(b>0){
                    	double y =(double) (b)/(a+b+c);
						p[a+1][b-1][c] += (double) p[a][b][c]*y;
						ev[a+1][b-1][c] += ev[a][b][c]*y;
							}
                    
                    if(c>0){
                    	double z =(double) (c)/(a+b+c);
						p[a][b+1][c-1] += (double) p[a][b][c]*z;
						ev[a][b+1][c-1] += ev[a][b][c] * z;
						}

                }
            }
        }

//    cout<<p[0][0][0]<<"\n";
//    cout<<p[cnt[1]][cnt[2]][cnt[3]];
	cout<<setprecision(10)<<fixed<<ev[0][0][0]+cnt[1]+2*cnt[2]+3*cnt[3];

    }
    return 0;
}    