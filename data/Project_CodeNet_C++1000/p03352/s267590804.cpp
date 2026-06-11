#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll X;
    cin >> X;
    if(X == 1){
        cout << 1 << endl;
        return 0;
    }
    double ans = 0; 
    for(int i = 2; i < 11; i++){
        for(int j = 2; j <= 35; j++){
            if(pow(j,i) <= X ){
                ans = max(ans, pow(j,i));
            }
        }
    }
    cout << ans << endl;
}
