#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll N;cin>>N;
    double z;
    rep(i,1,3501){
        rep(j,i,3501){
            z=(double)(N*i*j)/(4*i*j-N*i-N*j);
            if(floor(z)==z&&z!=0&&z>0&&z<999999999){
                cout<<i<<" "<<j<<" "<<(ll)z<<endl;
                return 0;
            }
        }
    }
}





