#include <bits/stdc++.h>
using namespace std;
int main(){
    // Your code here!
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    if (a>=b) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        
    }
}