#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;
    int a,s,m;
    a=A+B;
    s=A-B;
    m=A*B;
    cout << max({a,s,m}) << endl;
    return 0;
}