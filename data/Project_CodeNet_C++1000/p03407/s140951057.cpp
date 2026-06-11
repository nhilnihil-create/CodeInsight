#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。
int main () {
    int A , B , C;
    cin >> A >> B >> C;
    int total = A + B;
    if(total >= C){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
