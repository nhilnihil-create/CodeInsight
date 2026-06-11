#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int a1;
    int a2;
    if( b > a) a1 = b-a;
    else if(a==b) a1 = d;
    else a1 = a-b;

    if(c > b) a2 = c - b;
    else if(b==c) a2 = d;
    else a2 = b-c;

    int c1;
    if(c > a) c1 = c-a;
    else if(a==c) c1 = c1 = d;
    else c1 = a-c;

    if(a1 <= d && a2 <= d) cout << "Yes" << endl;
    else if (c1 <= d) cout << "Yes" << endl;
    else cout << "No" << endl;
}