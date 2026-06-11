#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,ans;
    cin >> a >> b;

    double x=(double)(a+b)/2.0;
    if((int)(x*10.0)%10!=0){
         ans = (int)x+1;
    }else{
        ans = (int)x;
    }
    cout << ans << endl;
    
}