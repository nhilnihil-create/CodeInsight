#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n[4];

    for (int i = 0; i < 4; i++){
        n[i] = 0;
    }

    for (int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        n[a - 1] += 1;
        n[b - 1] += 1;
    }

    bool A = true;
    
    for (int i = 0; i < 4; i++){
        if (n[i] >= 3){
            A = false;
        }
    }

    if (A == true){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}