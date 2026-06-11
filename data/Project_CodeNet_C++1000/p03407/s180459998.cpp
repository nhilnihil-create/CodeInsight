#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int p,c,a,b;
    cin>>a>>b>>p;
    c=a+b;
    if ((a>500 && b>500) || ( a==0 || b==0)) {
        cout << "No";
        exit(1);
    }
    else {
        if (p <= c) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}
