#include <iostream>

using namespace std;
const int MAXN = 1e5+5;
int arr[MAXN];
int main(){
    int n,z,w;
    cin>>n>>z>>w;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n == 1){
        cout<<abs(arr[1]-w)<<endl;
        return 0;
    }
    cout<<max(abs(arr[n]-w),abs(arr[n-1]-arr[n]));
}