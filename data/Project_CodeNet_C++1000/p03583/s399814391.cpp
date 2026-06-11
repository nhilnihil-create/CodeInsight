#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    double N;
    cin>>N;
    for(double h=1; h<=3500; ++h){
        for(double n=1; n<=3500; ++n){
            double w=(N*n*h)/(4*h*n-N*n-N*h);
            ll x=w;
            if(x==w&&w>0){cout<<h<<" "<<n<<" "<<(ll)w<<endl; return 0;}
        }
    }
}