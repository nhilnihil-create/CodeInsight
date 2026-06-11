#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
        a[i]%=2;
    }
    int ans = pow(3, n);
    int rmv=1;
    //cout<<n;
    for (int i = 0;i<n;i++){
        if (a[i]==0){
            rmv*=2;
        }
    }
    cout<<ans-rmv;
}
