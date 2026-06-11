#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll N, M;
    cin >> N >> M;

    ll innerN = 0;
    ll innerM = 0;
    if(N >= 3){
        innerN = N - 2;
    }else if(N == 1) {
        innerN = 1;
    }
    if(M >= 3){
        innerM = M - 2;
    }else if(M == 1) {
        innerM = 1;
    }

    cout << (innerN * innerM) << endl;

    return 0;
}