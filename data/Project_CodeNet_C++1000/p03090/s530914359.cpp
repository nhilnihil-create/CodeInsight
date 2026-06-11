#include <iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    cout<<n*(n-1)/2-n/2<<endl;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i+j+(n%2)-1!=n)cout<<i<<" "<<j<<endl;
        }
    }return 0;
}