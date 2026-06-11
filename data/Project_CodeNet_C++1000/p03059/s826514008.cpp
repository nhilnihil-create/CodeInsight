#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int a, b, c, resp = 0;

    cin >> a >> b >> c;

    for(int i = a; i <= c; i += a){
        resp += b;
    }

    cout << resp << endl;

    return 0;

}