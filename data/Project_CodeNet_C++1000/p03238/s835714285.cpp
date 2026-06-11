#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int N;
    cin >> N;
    if(N == 1){
        cout << "Hello World" << endl;
    }else{
        int A,B;
        cin >> A >> B;
        cout << A+B << endl;
    }
}

