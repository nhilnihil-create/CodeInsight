#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 0, A = 0;
    int rest = 0;
    
    cin >> N >> A;
    
    if(N >= 500){
        rest = N % 500;
        if (rest <= A){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        rest = N;
        if (rest <= A){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}