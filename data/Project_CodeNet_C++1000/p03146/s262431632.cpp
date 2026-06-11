#include <bits/stdc++.h>
using namespace std;


int main(){
    int init_s;
    cin >> init_s;

    int val = init_s;

    int i = 2;
    while(true){
        if(val == 4 || val == 2 || val == 1){
            cout << i + 2 << endl;
            break;
        }

        if (val % 2 == 0){
            val = val/2;
        }else{
            val = 3*val+1;
        }


        i += 1;
    }
    return 0;
}