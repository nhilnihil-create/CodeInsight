#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
    int n;cin>>n;
    const int MAX_N = 35000;
    
    
    for(ll i=1;i<MAX_N;++i){
        for(ll j=1;j<=i;++j){
            ll tmp1 = n*i*j;
            ll tmp2 = 4*i*j - i*n - j*n;
            ll tmp3 = tmp1/tmp2;
            if(tmp2>0 && tmp1%tmp2==0 && tmp3>0){
                cout<<i<<" "<<j<<" "<<tmp3<<endl;
                return 0;
            }
        }
    }
	return 0;
}