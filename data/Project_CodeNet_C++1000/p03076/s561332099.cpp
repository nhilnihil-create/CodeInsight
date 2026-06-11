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

// 1 way is to find compute all the sorted permutations and find the 
// positions of the current permutation.

int _find(ll a,ll b){
    if(a<=0 && b>=0){
        return 0;
    }
    // a,b
    if(a>0){
        return 1;
    }
    
    return (b-a+1)%2==0 ? 1:-1;
    
}

int convert(int n){
    int rem=n%10;
    if(rem==0){
        return n;
    }
    int miss=10-rem;
    return n+miss;
}
int remain(int n){
    int r=n%10;
    int w = r==0 ? 10 : r;
    return w;
}
void solve(){
    vi arr(5);
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    sort(all(arr),[&](int a,int b){
        
        return remain(a) > remain(b);
    });
    int tim=0;
    for(int i=0;i<4;i++){
        int t=convert(arr[i]);
        // cout<<arr[i]<<" "<<t<<" ";
        tim+=t;
        // cout<<tim<<endl;
    }
    tim+=arr[4];
    cout<<tim<<endl;
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