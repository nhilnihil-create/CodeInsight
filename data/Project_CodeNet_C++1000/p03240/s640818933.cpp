#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll x[105],y[105],h[105];
ll z=0;
ll s;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]!=0){
            s=i;
        }
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            ll H=h[s]+abs(x[s]-i)+abs(y[s]-j);
            bool t=true;
            for(int k=0;k<n;k++){
                if(max(H-abs(i-x[k])-abs(j-y[k]),z)!=h[k]){
                    t=false;
                }
            }
            if(t&&H!=0){
                cout<<i<<" "<<j<<" "<<H<<endl;
                return 0;
            }
        }
    }

}

