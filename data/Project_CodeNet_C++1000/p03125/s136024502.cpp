#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main(){
    ll A, B;
    cin >> A >> B;
    if(B % A == 0){
        cout << A + B << endl;
    }
    else{
        cout << B - A << endl;
    }
    return 0;
}