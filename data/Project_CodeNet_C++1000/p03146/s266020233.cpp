#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!



void solve(){
    int s;
    cin>>s;
    set<int> st;
    st.insert(s);
    
    int curr=s;
    int i=1;
    while(1){
        i++;
        curr=(curr&1)?3*curr+1:curr/2;
        if(st.find(curr)!=st.end()){
            cout<<i;
            return ;
        }    
        st.insert(curr);
    }
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