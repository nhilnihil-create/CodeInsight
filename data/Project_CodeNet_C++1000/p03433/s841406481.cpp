#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A;
    cin >> N >> A;
    while(true){
        N -= 500;
        if(N < 0){
            N += 500;
            break;
        }
    }
    if(N <= A){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}