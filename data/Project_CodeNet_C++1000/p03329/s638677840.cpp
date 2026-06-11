#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;
    vector<ll> w(100005,mod);
    w[0]=0; w[1]=1;

    for(int i=2; i<=n; i++){
        w[i]=min(w[i],w[i-1]+1);
        for(int j=6; j<=i; j*=6){
            w[i]=min(w[i],w[i-j]+1);
        }
        for(int j=9; j<=i; j*=9){
            w[i]=min(w[i],w[i-j]+1);
        }
    }
    cout << w[n] << endl;
    
    return 0;
}