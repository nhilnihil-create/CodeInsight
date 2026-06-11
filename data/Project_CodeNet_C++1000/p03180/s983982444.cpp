#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll INF = LONG_LONG_MAX;
const int MAXN = 16;

void ri(int &n){
    scanf("%d",&n);
}
ll sumas[1<<MAXN];
ll dp[1<<MAXN];

ll go(int mask){
    ll &r = dp[mask];
    if(mask==0) return r=0;
    if(__builtin_popcount(mask)==1) return r=0;
    if(r!=-INF){
        return r;
    }
    r= sumas[mask];
    for(int subset= mask; subset; subset= (subset-1) & mask){
        r= max(r, sumas[subset]+ sumas[subset^mask]);
        if(subset != mask){
            r= max(r, go(subset)+ go(subset^mask));
        }
    }
    return r;
}

int main(){
    int n;
    ri(n);
    int matrix[n][n];
    forn(i,n){
        forn(j,n){
            ri(matrix[i][j]);
        }
    }
    for(int mask= 0; mask< (1<<n); ++mask){
        forn(i,n){
            if((1<<i)&mask){
                fore(j,i+1,n-1){
                    if((1<<j)&mask){
                        sumas[mask]+= matrix[i][j];
                    }
                }
            }
        }
    }
    forn(i,(1<<MAXN)){
        dp[i]=-INF;
    }
    ll r = sumas[(1<<n)-1];
    r= max(r, go((1<<n)-1));
    printf("%lld\n", r);
}

