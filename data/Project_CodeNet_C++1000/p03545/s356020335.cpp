#include <bits/stdc++.h>
using namespace std;

int main(){
    int input;
    cin >> input;
    int D = input%10;
    int C = (input%100 - D)/10;
    int B = (input%1000 - C*10 - D)/100;
    int A = (input - B*100 - C*10 -D)/1000;

    bool is_seven = false;
    int op1, op2, op3;
    for(int i=0; i<pow(2,3);i++){
        op1 = (i>>0 & 1) ? 1 : -1;
        op2 = (i>>1 & 1) ? 1 : -1;
        op3 = (i>>2 & 1) ? 1 : -1;

        if(A + op1*B + op2*C + op3*D == 7){
            is_seven = true;
            break;
        } 
    }

    if(is_seven){
        string st_op1 = (op1 == 1) ? "+" : "-";
        string st_op2 = (op2 == 1) ? "+" : "-";
        string st_op3 = (op3 == 1) ? "+" : "-";
        cout << to_string(A) << st_op1 << to_string(B) << st_op2 << to_string(C) << st_op3 << to_string(D) << "=7" << endl;
    }else{
        cout << "unexpected input" << endl;
    }
    return 0;

} 
