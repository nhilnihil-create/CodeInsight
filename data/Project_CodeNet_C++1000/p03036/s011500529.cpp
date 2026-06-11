#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long a,b,c;
    cin >> a >> b >> c;
    for(int i=0;i<10;i++){
        long long d = c*a-b;
        cout << d << endl;
        c = d;
    }
}
