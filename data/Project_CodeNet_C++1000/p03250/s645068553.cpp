#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==max(a,max(b,c)))cout << a*10+b+c << endl;
    else if(b==max(a,max(b,c)))cout << b*10+a+c << endl;
    else if(c==max(a,max(b,c)))cout << c*10+a+b << endl;
}
