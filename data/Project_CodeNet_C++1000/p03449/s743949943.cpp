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
    int n;
    cin>>n;
    
    vector<vi> grid(2,vi (n,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    for(int i=1;i<n;i++){
        grid[0][i]+=grid[0][i-1];
    }
    
    for(int i=n-1-1;i>=0;i--){
        grid[1][i]+=grid[1][i+1];
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,grid[0][i]+grid[1][i]);
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