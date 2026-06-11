#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, A;
    cin >> N >> A;
    int x = N % 500;
    if (x <= A) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}