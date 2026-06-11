#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// 素数判定O(√n)
bool is_prime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans;
    for(int i=2;i<=55555;i++){
        if(is_prime(i) && i%5==1) ans.push_back(i); 
    }

    rep(i,n) cout<<ans[i]<<" ";
    cout<<endl;
}


 