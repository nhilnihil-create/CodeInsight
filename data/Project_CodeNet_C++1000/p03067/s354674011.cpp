#include <bits/stdc++.h>
using namespace std;

template<typename T>
T mid(T a, T b, T c){
    return (a + b + c - max({a, b, c}) - min({a, b, c}));
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(mid(a, b, c) == c)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}