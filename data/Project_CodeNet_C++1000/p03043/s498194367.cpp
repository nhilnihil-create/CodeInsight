#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    double ans=0;
    for(int i=1;i<=n;i++){
        double x=1.0/n;
        double c=i;
        while(c<k){
            c*=2;
            x/=2;
        }
        ans+=x;
    }
    cout<<fixed<<setprecision(16);
    cout<<ans<<endl;
    return 0;
}