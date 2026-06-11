#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int temp1,temp2;
    temp1=temp2=0;
    bool f=(n-1)%2;
    for(int i=n-1;i>=0;i--){
        if(i%2==f)temp1+=arr[i];
        else temp2+=arr[i];
    }
    cout<<temp1-temp2;
}

