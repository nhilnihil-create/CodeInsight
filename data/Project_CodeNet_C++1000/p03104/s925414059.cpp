#include<bits/stdc++.h>
using namespace std;
long xoror(long n){
    long ans = 0;
    for(long i=1;i<=n;i*=2){
        if(i==1){
            if((n-1)%4 < 2)ans++;
        }else{
            if(n%(i*2)>=i && n%2==0)ans += i;
        }
    }
    return ans;
}

int main(){
    long a,b;
    cin >> a >> b;
    long ans;
    if(a==0)ans = xoror(b);
    else ans = xoror(a-1) ^ xoror(b);
    cout << ans << endl;
    
}