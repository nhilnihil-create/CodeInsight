#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    int res = 0;
    while(n>0){
        if(res==0){
            res++; n -= k; //cout << n << "," << k << endl;
        }else{
            res++; n -= (k-1); //cout << n << "," << k << endl;
        }
    }
    cout << res << endl;
    return 0;
}