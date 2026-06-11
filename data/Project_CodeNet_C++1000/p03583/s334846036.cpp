#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int (i)=(l);(i)<(r);(i)++)
using namespace std;
int main(){
    //cout.precision(10);
    ll N,w;
    cin>>N;
    for(ll h=3500;h>0;h--){
        for(ll n=3500;n>0;n--){
            if(!((N*h*n)%(4*h*n-N*(n+h)))){
                w=(N*h*n)/(4*h*n-N*(n+h));
                if(w>0){
                    cout<<h<<" "<<n<<" "<<w<<endl;
                    return 0;
                }
            }
        }
    }
}