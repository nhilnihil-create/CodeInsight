#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int x1, x2, x3, x4;
    cin >> N;
    x1 = N % 10;
    N /= 10;
    x2 = N % 10;
    N /= 10;
    x3 = N % 10;
    N /= 10;
    x4 = N % 10;
    if(((x1 == x2) && (x2 == x3)) || ((x2 == x3) && (x3 == x4))){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}