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

bool isPalindrome(int n){
    string str=to_string(n);
    int lo=0,hi=str.l()-1;
    while(lo<hi){
        if(str[lo]!=str[hi]){
            return 0;
        }
        lo++;
        hi--;
    }
    return 1;
}
void solve(){
    int l,r;
    cin>>l>>r;
    
    int cnt=0;
    for(int i=l;i<=r;i++){
        cnt+=isPalindrome(i);
    }
    cout<<cnt<<endl;
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