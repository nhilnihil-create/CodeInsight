#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
int main(){
    double n,k;
    cin>>n>>k;
    double w=0;
    for(int i=1;i<=n;i++){
        double a=1.0/n;
        int x=i;
        while(x<k){
            x*=2;
            a/=2;
        }
        w+=a;
    }
    cout<<fixed<<setprecision(12)<<w<<endl;
    return 0;
}