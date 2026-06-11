#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;


int n;
ll a[20][20], dp[1<<17], suma[1<<17];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i =0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>a[i][j];
        }
    }
    for(int mask = 1; mask<(1<<n); ++mask){
        for(int i =0; i<n; ++i)
            if(mask&(1<<i))
                for(int j =i+1; j<n; ++j)
                    if(mask&(1<<j))
                        suma[mask]+=a[i][j];
    }
    for(int mask = 1; mask<(1<<n); ++mask){
        dp[mask] = suma[mask];
        for(int s = mask; s; s=(s-1)&mask){
            int xs = mask^s;
            dp[mask] = max(dp[mask],dp[s]+dp[xs]);
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
    return 0;
}