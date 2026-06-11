#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c,k;
    cin >> a >> b >> c >> k;
    if(abs(a-b)>=1000000000000000000){cout << "Ubfair" << endl;}
    else{
        if(k%2==0)cout << a-b << endl;
        else cout << b-a << endl;
    }
    return 0;
}