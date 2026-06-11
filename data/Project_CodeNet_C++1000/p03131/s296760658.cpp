#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    ll K,A,B;
    cin>>K>>A>>B;

    ll have=1;

    ll a=min(K,A-1);
    have+=a;
    K-=a;
    if(K==0){
        cout<<have<<endl;
        return 0;
    }

    if(A+2<=B){
        ll cnt=K/2;
        have+=cnt*(B-A);
        if(K%2==1) have++;
        cout<<have<<endl;
    }
    else cout<<have+K<<endl;

}

