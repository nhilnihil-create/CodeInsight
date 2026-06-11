#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    long ans = 0;
    for(int b=k+1;b<=n;b++){
        int a=max(k,1);
        while(a<=n){
            ans += min(b-(a%b),n-a+1);
            a = (a/b + 1) * b + k; 
        }
    }
    cout<<ans<<endl;
}