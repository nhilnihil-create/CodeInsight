#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    string A , B;
    cin >> A;
    cin >> B;
    reverse(A.begin() , A.end());
    if(A == B){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}