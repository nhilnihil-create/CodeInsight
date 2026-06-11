#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll D,N;
    cin >> D >>N;
    if(N==100){
        N++;
    }

    ll num =1;
    for(int i=0;i<D;i++){
        num *= 100;
    }
    cout << num*N << endl;

    return 0;
}