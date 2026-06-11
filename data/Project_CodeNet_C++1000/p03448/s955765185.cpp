#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.

ll _find(ll A,ll B,ll C,ll X){
    ll cnt=0;
    
    for(ll c=0;c<=C;c++){
        if(c*50>X){
            break;
        }
        for(ll b=0;b<=B;b++){
            if(b*100>X){
                break;
            }
            for(ll a=0;a<=A;a++){
                if(a*500>X){
                    break;
                }
                if( (a*500 + b*100 + c*50) == X){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}


void solve(){
    ll sum;
    ll a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>sum;
    
    cout<<_find(a,b,c,sum);
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}