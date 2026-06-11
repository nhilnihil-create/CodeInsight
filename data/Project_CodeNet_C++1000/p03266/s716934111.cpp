#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;
    cin >> n >> k;
    long long int a,b;
    long long int ans=0;
    for(int i=0;i<k;i++){
        if(i==0)ans+=(n/k)*(n/k)*(n/k);
        else{
            if(n%k>=i)a=n/k+1;
            else a=n/k;
            if(n%k>=k-i)b=n/k+1;
            else b=n/k;
            if((2*k-2*i)%k==0)ans+=a*b*b;
    }
    }
    cout << ans << endl;
}