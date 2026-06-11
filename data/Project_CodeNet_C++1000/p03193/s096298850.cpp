#include <iostream>
using namespace std;
int main(void){
    int n,h,w;
    cin>>n>>h>>w;
    int ans=0;
    int a,b;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        ans+=(a>=h&&b>=w );
    }
    cout<<ans;
};
