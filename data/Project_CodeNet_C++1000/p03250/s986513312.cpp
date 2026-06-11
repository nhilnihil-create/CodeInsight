#include <bits/stdc++.h>
using namespace std;  

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    cout << a+b+c - max({a, b, c}) + max({a, b, c}) * 10 << endl;
    
    return (0);
}
