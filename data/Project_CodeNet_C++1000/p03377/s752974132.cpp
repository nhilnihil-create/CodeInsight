#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){

    int a, b, x;
    cin >> a >> b >> x;
    for(int i = 0; i <= b; i++){
        if (a + i == x){
            cout << "YES" << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;

}