#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c;
    bool flag=false;
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'Y')flag=true; 
    }
    if(flag) cout << "Four";
    else cout << "Three";
}