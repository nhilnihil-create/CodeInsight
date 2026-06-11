#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> T(999);
    T.at(0)=1;
    for (int i=1; i<999; i++) T.at(i)=T.at(i-1)+i+1;
    for (int i=1; i<999; i++) {
        if(T.at(i-1)-a == T.at(i)-b) {
            cout << T.at(i-1)-a << "\n";
        }
    }
}