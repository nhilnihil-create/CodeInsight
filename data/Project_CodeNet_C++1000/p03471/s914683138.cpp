#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,y;
    bool flg = false;
    cin >> n >> y;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n-i;++j){
            int k = n-i-j;
            if(10000*i+5000*j+1000*k == y){
                flg = true;
                cout << i << " " << j <<  " " << k << endl;
                return 0;
            }
        }
    }
    if(!flg) cout << "-1 -1 -1" << endl;
    return 0;
}
