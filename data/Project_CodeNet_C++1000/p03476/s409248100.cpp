#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int a[100010];

int main(){
    vector<int> is_prime(100010,1);
    is_prime[0]=0,is_prime[1]=0;
    for(int i=2;i<100010;i++){
        if(!is_prime[i]) continue;
        for(int j=i*2;j<100010;j+=i) is_prime[j]=0;
    }
    rep(i,100010){
        if(i%2==0) continue;
        if(is_prime[i] && is_prime[(i+1)/2]) a[i]=1;
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
