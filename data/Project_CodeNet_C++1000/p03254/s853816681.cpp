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
    long long n,x;
    cin>>n>>x;
    long long arr[n],sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
    }
    ll temp=x;
    sort(arr,arr+n);
    int i=0;
    while(i<n&&x>0){
        if(arr[i]<=x){
            x=x-arr[i];
        }
        else break;
        i++;
    }
    if(sum==temp)cout<<n;
    else if(sum<temp)cout<<n-1;
    else
    cout<<i;
}

