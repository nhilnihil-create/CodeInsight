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

int a[100010];

int main(){
    for(int i=1;i<100010;i+=2){
        if(is_prime(i) && is_prime((i+1)/2)) a[i]=1;
    }


    vector<int> sum(100010,0);
    rep(i,100005){
        sum[i+1]=sum[i]+a[i];
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r+1]-sum[l]<<endl;
    }

}
