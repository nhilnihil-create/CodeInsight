#include <iostream>
#include<iomanip>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;



int main() {
    double n,k;
    cin>>n>>k;
    double ans=0;
    vector<double>p(n,1/n);

    rep(i,n){
        if(i<k-1)p[i]*=0.5;
        double b=2;
        while(b<(double)(k/(i+1))){
            b *=2;
            p[i] *= 0.5;
        }
        ans+=p[i];
        
    }
    cout<<fixed<<setprecision(16);
    cout<<(double)ans<<endl;

    return 0;
}