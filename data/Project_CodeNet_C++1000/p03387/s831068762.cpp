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

int _find(int a,int b,int c){
    if(a==b && b==c){
        return 0;
    }
    vector<int> v={a,b,c};
    sort(all(v));
    a=v[0];b=v[1];c=v[2];
    if(a==b && c==b+1){
        return 1+_find(a+1,b+1,c);
    }
    return 1+_find(a+2,b,c);
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<_find(a,b,c)<<endl;
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