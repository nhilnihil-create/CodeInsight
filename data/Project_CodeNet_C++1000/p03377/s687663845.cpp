#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, N;
    cin >> A >> B >> N;

    if(N < A){
        cout << "NO" << endl;
    }
    else if(N - A <= B){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}