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

int sod(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int _find(int n,int l,int r){
    int ans=0;
    for(int i=1;i<=n;i++){
        int s=sod(i);
        if(s>=l && s<=r){
            ans+=i;
        }
    }
    return ans;
}
void solve(){
    
    int n,l,r;
    cin>>n>>l>>r;
    
    cout<<_find(n,l,r);
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