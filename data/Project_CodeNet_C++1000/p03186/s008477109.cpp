#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=0,b=0,c=0;
    cin >> a >> b >> c;
    if(a+b<c)cout << a+b+b+1 << endl;
    else cout << b+c << endl;
    return 0;
}