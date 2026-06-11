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
    string str;
    cin>>str;
    int l=str.l();
    int ans=0,curr=0;
    bool flag=true;
    string xx="ACTG";
    
    for(int i=0;i<l;i++){
        if(xx.find(str[i])==string::npos){
            curr=0;
        }
        else{
            curr++;
            ans=max(ans,curr);
        }
    }
    cout<<ans;
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