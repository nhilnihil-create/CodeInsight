#include<iostream>
#include<stdio.h>

using namespace std;

int x[4];
int main () {
    bool flag = true;
    for(int i=0; i<3; i++) {
        int a,b;
        cin >> a >> b;
        x[a]++;
        x[b]++;
        if( x[a] == 3 || x[b] == 3 ) flag = false;
    }
    cout << ( flag ? "YES" : "NO") << endl;
    return 0;
}
