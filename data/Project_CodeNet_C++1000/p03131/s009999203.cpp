#include<bits/stdc++.h>
using namespace std;

int main(){
    long long k,a,b,change,pls;
    cin >> k >> a >> b;
    k++;

    if(b - a < 2 || k <= a){
        cout << k<< endl;
        return 0;
    }
    else {
        k -= a;
        change = k / 2;
        pls = k % 2;
        cout << a + change * (b - a) + pls << endl;
    }
}
