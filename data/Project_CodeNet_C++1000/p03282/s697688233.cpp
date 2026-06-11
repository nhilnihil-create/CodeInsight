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

ll _find(string &str){
    
    for(ll i=0;i<(ll)str.length();i++){
        if(str[i]!='1'){return i;}
    }
    return -1;
}

void solve(){
    string str;
    ll k;
    cin>>str;
    cin>>k;
    
    ll p=_find(str);
    if(p==-1){
        cout<<1<<endl;
        return ;
    }
    else{
        k--;
        if(k>=p){
            cout<<str[p];
        }
        else{
            cout<<1;
        }
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