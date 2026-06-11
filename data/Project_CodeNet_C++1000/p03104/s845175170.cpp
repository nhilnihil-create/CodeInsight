#include<bits/stdc++.h>
using namespace std;
long xoror(long n){
    long ans = 0;
    for(long i=1;i<=n;i*=2){
        if(i==1){
            if(n%4 == 1 || n%4==2)ans += 1;
        }else{
            if(n % (i*2) >= i && n%2==0)ans += i;
        }
    }
    return ans;
}





int main(){
    long a,b;
    cin >> a >> b;
    long aa = 0;
    if(a>0)aa = xoror(a-1);
    long bb = xoror(b);
    cout << (aa^bb) << endl;
    
}
