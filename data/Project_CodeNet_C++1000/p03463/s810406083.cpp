/*
MOVE AND WIN
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    while(1){
        if(++a == b){
            cout << "Borys" << endl;
            break;
        }else if(a == --b){
            cout << "Alice" << endl;
            break;
        }
    }
    return 0;
}
