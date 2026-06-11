#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int A;

    cin >> N >> A;

    int i;
    i = N % 500;

    if(i <= A){
        cout << "Yes" << endl;
     }else{
        cout << "No" << endl;
    }
}