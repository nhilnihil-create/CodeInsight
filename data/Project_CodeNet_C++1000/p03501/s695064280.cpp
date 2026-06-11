#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B, x;
    cin >> N >> A >> B;
    int x1, x2;
    x1 = A * N;
    x2 = B;
    if(x1 <= x2){
        cout << x1 << endl;
    }else{
        cout << x2 << endl;
    }
}