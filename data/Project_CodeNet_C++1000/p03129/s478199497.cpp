#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int s = 1;
    int cou = 1;
    while (1){
        if(cou == k || s > n){
            if(s > n){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
            break;
        }
        s += 2;
        cou++;
    }
    
}