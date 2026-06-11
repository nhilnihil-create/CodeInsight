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
    string str;
    cin>>str;
    
    int a=0;// if the final string : 0101010101
    int b=0;// if the final string : 1010101010
    
    for(int i=0;i<str.l();i++){
        // for a : odd index must be 0 and even must be 0
        a+=(i%2==0) ? (str[i]!='0') : (str[i]!='1') ;
        
        // for b : odd index must be 0 and even must be 1
        b+=(i%2==0) ? (str[i]!='1') : (str[i]!='0') ;
    }
    cout<<min(a,b);
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