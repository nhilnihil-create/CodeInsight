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


void solve(){
    int n,m;
    cin>>n>>m;
    
    vi freq(m+1,0);
    for(int i=0;i<n;i++){
        int sz;
        cin>>sz;
        for(int j=0;j<sz;j++){
            int f;
            cin>>f;
            freq[f]++;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        if(freq[i]==n){
            ans++;
        }
    }
    cout<<ans<<endl;
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