#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    double ans = 0;
    for(int i=1;i<=n;i++){
        double a = (double)1/n;
        if(i<k){
            int b = i;
            double cnt=1;
            while(b<k){
                b*=2;
                cnt*=2;
            }
            a*=1/cnt;
        }
        ans+=a;
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}
