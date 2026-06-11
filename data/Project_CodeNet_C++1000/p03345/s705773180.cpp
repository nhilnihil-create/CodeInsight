#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,k,border,ans;
    border = pow(10,18);
    cin >> a >> b >> c >> k;
    if(k == 0){
        ans=a-b;
    }else{
        if(k%2==0)k=2;
        if(k%2==1)k=1;
        for(int i = 0; i < k; i++){
            long long tmpA,tmpB,tmpC;
            tmpA = b+c;
            tmpB = a+c;
            tmpC = a+b;
            ans = tmpA-tmpB;
            a = tmpA;
            b = tmpB;
            c = tmpC;
            //cout << a << " " << b << " " << c << " " << ans <<endl;
        }
    }
    if(abs(ans)>=border){
        cout << "Unfair" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}