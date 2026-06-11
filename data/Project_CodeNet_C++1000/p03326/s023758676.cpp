#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll mypow(ll x,ll n){
    ll ret=1;
    while(n>0){
        if(n&1==1){
            ret *=x;
        }
        x *=x;
        n >>=1;
    }
    return ret;
}

int main() {
    ll N,M;
    cin >> N >>M;
    vector<ll> x(N),y(N),z(N);
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans =0;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++){
        ll temp=0;
        vector<ll> A(N);
        for(int s=0;s<N;s++){
            A[s] = (mypow(-1,i)*x[s] + mypow(-1,j)*y[s]+mypow(-1,k)*z[s]);
        }
        sort(A.rbegin(),A.rend());
        for(int s=0;s<M;s++){
            // cerr <<"z=" << A[s] << endl; 
            temp += A[s];
        }
        // cerr <<"temp="<<temp << endl;
        ans = max(ans,temp);
    }
    cout << ans << endl;

    return 0;
}