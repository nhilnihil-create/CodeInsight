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

int remSum(int m,vi arr){
    int c=0;
    for(int x:arr){
        c+=(m%x);
    }
    return c;
}

void solve(){
    
    int n;
    cin>>n;
    
    
    int sum=0;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        sum+=c;
    }
    
    cout<<sum-n<<endl;
    
    
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