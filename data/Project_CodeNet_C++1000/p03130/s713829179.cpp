#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, k;
    int check[4];
    for(int i = 0; i < 4; i++){
        check[i] = 0;
    }
    for(int i = 0; i < 3; i++){
        cin >> t >> k;
        check[t - 1]++;
        check[k - 1]++;
    }

    int flag_1 = 0;
    int flag_2 = 0;
    for(int i = 0; i < 4; i++){
        if(check[i] == 1){
            flag_1++;
        }else if(check[i] == 2){
            flag_2++;
        }else{
            break;
        }
    }

    if(flag_1 == 2 && flag_2 == 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}