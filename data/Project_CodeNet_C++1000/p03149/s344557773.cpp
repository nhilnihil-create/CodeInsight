#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[4];
    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }

    int che[4] = {0, 0, 0, 0};
    int k[4] = {1, 9, 7, 4};
    int flag = 0;
    for(int i = 0; i < 4; i++){
        flag = 0;
        for(int j = 0; j < 4; j++){
            if(a[i] == k[j] && che[j] == 0){
                flag = 1;
                che[j] = 1;
            }
        }

        if(flag == 0){
            break;
        }
    }

    if(flag == 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}