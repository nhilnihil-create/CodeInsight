#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,x;
    cin >> x;
    bool flag = false;
    for (int i = 0; i <= 26; i++){
        for (int j = 0; j <= 15; j++){
            if(4*i+7*j == x){
                flag = true;
                break;
            }
        }
        if(flag == true) break;
    }
    if(flag == true){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}