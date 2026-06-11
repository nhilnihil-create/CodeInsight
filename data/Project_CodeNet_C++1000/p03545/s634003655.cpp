#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    char s,t,u,v;
    cin >> s >> t >> u >> v;
    int a,b,c,d;
    a=s-'0';b=t-'0';c=u-'0';d=v-'0';
    if(a+b+c+d==7){
        cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl;
        return 0;
    }
    if(a+b+c-d==7){
        cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl;
        return 0;
    }
    if(a+b-c+d==7){
        cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl;
        return 0;
    }
    if(a+b-c-d==7){
        cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl;
        return 0;
    }
    if(a-b+c+d==7){
        cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl;
        return 0;
    }
    if(a-b+c-d==7){
        cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl;
        return 0;
    }
    if(a-b-c+d==7){
        cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl;
        return 0;
    }
    if(a-b-c-d==7){
        cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl;
        return 0;
    }
}