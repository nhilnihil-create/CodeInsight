#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll int n,sum=0,count=1,a[200001],b[200002];
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if(i==0){
            b[0]=0;
        }else{
            b[i]=b[i-1]+a[i-1];
        }
    }
    b[n]=b[n-1]+a[n-1];
    sort(b,b+n+1);
    for (int i=1;i<=n;i++){
        if(b[i]==b[i-1]){
            sum+=count;
            count++;
        }else{
            count=1;
        }
    }
    cout << sum;
}