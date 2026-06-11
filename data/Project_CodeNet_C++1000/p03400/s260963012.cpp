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
int get(int n){
    if(n%2==0)return n/2;
    else return 3*n+1;
}
int main(){
    int n,d,x;
    cin>>n>>d>>x;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=n;
    for(int i=0;i<n;i++){
        ans=ans+(d-1)/arr[i];
    }
    cout<<ans+x;
}

