#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int m = max(a, max(b, c));
    for(int i = 0;i < k;i++){
        m *= 2;
    }
    if(max({a, b, c}) == c)cout << a + b + m << endl;
    else if(max({a, b, c}) == b)cout << a + c + m << endl;
    else if(max({a, b, c}) == a)cout << b + c + m << endl;


}