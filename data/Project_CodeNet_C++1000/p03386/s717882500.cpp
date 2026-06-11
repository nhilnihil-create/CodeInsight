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

int _find(vector<string> &arr,int n){
    set<string> s;
    if(n==0){return 1;}
    s.insert(arr[0]);
    int lastCh=arr[0].back();
    for(int i=1;i<n;i++){
        if(s.count(arr[i])){
            return false;
        }
        if(arr[i][0]!=lastCh){
            return false;
        }
        s.insert(arr[i]);
        lastCh=arr[i].back();
    }
    return 1;
}

void solve(){
    
    int a,b,k;
    cin>>a>>b>>k;
    set<int> s;
    int cnt=0;
    for(int i=a;i<=b && cnt++<k;i++){
        s.insert(i);
    }
    cnt=0;
    for(int i=b;i>=a && cnt++<k;i--){
        s.insert(i);
    }
    for(auto i:s){
        cout<<i<<endl;
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