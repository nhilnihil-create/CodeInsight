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
    int n,g;
    cin>>n>>g;
    
    int st=1,en=1e5;
    int flag=1;
    while(g-->0){
        int l,r;
        cin>>l>>r;
        // total overlap
        if(st>l && en<r){
            continue;
        }// no overlap
        else if(r<st || en<l){
            flag=0;
        }
        else{// partial overlap
            st=max(st,l);
            en=min(en,r);
        }
    }
    if(flag){
        cout<<en-st+1;
    }
    else{
        cout<<0;
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