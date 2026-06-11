#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if(A < C && C < B){
        cout << "Yes";
    } else if(A > C && C > B){
        cout << "Yes";
    } else{
        cout << "No";
    }
    return 0;
}