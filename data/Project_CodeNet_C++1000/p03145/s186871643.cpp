#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b >> c;

    if(a > b && a > c)      cout << (b*c)/2 << "\n";
    else if(b > c && b > a) cout << (a*c)/2 << "\n";
    else                    cout << (a*b)/2 << "\n";

    return 0;
}