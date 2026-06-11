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
    int n;
    cin>>n;
    int arr[n];
    int good=1, bad=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0)bad=bad*2;
        good = good*3;
    }
    cout<<good-bad;
}