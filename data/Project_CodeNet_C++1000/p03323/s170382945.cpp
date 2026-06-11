#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    int blank = 16 - (A + B);
    int flag = 0;
    if(A<B){
        swap(A,B);
    }
    for(int i=0; i <= blank; i++){
        int C = A - i;
        if(abs(C - B) == 1 || abs(C - B) == 0){
            flag = 1;
        }
        else{
            continue;
        }
    }
    if(flag == 1){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }
}