#include <iostream>

using namespace std;
const int MAXN = 1e5+5;
int arr[MAXN];
int curr;
int mn = 1;
int n;
int mx=1;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];

        if(arr[mx]<arr[i]){
            mx = i;
        }
        if(arr[mn]>arr[i]){
            mn= i ;
        }
    }
    if(abs(arr[mx])>=abs(arr[mn])){
        curr = mx;
    }else{
        curr = mn;
        
    }
    cout<<2*(n-1)<<endl;
    for(int i=1;i<=n;i++){
        if(i == curr){
            continue;
        }
        cout<<curr<<" "<<i<<endl;
    }
    if(arr[curr]>=0){
        for(int i=1;i<n;i++){
            cout<<i<<" "<<i+1<<endl;
        }
    }else{
        for(int i=n;i>1;i--){
            cout<<i<<" "<<i-1<<endl;
        }
    }
}