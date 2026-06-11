#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 2e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr, arr+3);
    int ans=0;
    ans=(arr[2]-arr[1])+(arr[1]-arr[0]+1)/2;
    if(arr[1]%2!=arr[0]%2)ans++;
    cout<<ans;
}