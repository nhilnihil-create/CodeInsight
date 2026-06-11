#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    for(int i=max(a,b);i>min(a,b);i--) {
        if(i==c){cout << "Yes" << endl; return 0;}
    }
    cout << "No" << endl;
}
