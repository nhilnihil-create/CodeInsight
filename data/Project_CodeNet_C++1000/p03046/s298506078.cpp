#include<bits/stdc++.h>
using namespace std;
int main(){
    int m, k;
    cin >> m >> k;
    int power = 1;
    for(int i = 1; i <= m; i++){
        power = power * 2;
    }
    if(k >= power){
        cout << "-1";
        return 0;
    }
    if(m == 1 && k == 1){
        cout << "-1";
        return 0;
    }
    if(m == 1 && k == 0){
        cout << "0 0 1 1";
        return 0;
    }
    else{
        for(int i = 0; i < power; i++){
            if(i == k){
                continue;
            }
            cout << i << ' ';
        }
        cout << k << ' ';
        for(int i = power - 1; i >= 0; i--){
            if(i == k){
                continue;
            }
            cout << i << ' ';
        }
        cout << k << ' ';
    }
    return 0;
}