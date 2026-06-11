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

void sieve(int n,vector<bool> &expo){
    for(int i=2;i<=n;i++){
        for(int j=i*i;j<=n;j*=i){
            expo[j]=1;
        }
    }
}
int _find(int n,vector<bool> &expo){
    for(int i=n;i>=1;i--){
        if(expo[i]){
            return i;
        }
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    vector<bool> expo(n+1,false);
    sieve(n,expo);
    cout<<_find(n,expo);
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