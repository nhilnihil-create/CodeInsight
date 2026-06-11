#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A;
    cin >> N >> A;
    N %= 500;
    if(A == 0){
        cout << (N ? "No" : "Yes") << endl;
        return 0;
    }
    cout << (N/A > 0 ? "No" : "Yes") << endl;
    return 0;
}