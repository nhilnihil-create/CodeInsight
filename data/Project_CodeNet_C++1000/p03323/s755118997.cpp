#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    if(A>8 || B>8 || A+B>16){
        cout << ":(";
    }
    else{
        cout << "Yay!";
    }
    return 0;
}