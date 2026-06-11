#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int X,Y;
    cin >> X >> Y;
    int ans=1;
    if(X%Y==0) cout << -1 << endl;
    else{
    while(true){
        ans*=X;
        if(ans%Y!=0){
            cout << ans << endl;
            break;
        }
        
    }
    }
}