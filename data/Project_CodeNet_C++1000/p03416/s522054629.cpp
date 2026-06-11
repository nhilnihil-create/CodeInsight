#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int ans=0;
    int r,s,t,u;

    for(int i=a; i<=b; i++){
        r=i/10000;
        s=(i%10000)/1000;
        u=i%10;
        t=(i/10)%10;
        
        if(r==u && s==t) ans++;
    }
    cout << ans <<endl;
}