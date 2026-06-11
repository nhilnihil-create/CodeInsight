#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll a,b,k;
    cin>>a>>b>>k;

    rep(i,k){
        if(i%2==0){
            if(a%2==1)a--;
            a=a/2;
            b+=a;
        }else{
            if(b%2==1)b--;
            b=b/2;
            a+=b;
        }
    }
    cout<<a<<" "<<b<<endl;
}