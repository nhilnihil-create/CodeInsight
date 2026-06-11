#include <iostream>
using namespace std;
int n,a[100],ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&&a[i-1]==a[i]){
            a[i]=-1;
            ans++;
        }
    }
    cout<<ans;
}