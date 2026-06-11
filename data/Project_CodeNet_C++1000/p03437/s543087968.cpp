#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int x,y;
    cin >> x >> y;
    if(x >= y && x % y == 0)
    cout << -1 << endl;
    else
    {
        for(int i = x; i < 1e18; i += x){
        if(i % y != 0)
        {
            cout << i << endl;
            return 0;
        }
        }
    }
    
}