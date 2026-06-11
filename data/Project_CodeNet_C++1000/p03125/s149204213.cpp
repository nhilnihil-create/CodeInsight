#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e9+7;

int main(){

    ll a,b;
    cin >>a>>b;
    if (b % a == 0){
        cout<< a+b;
    }else{
       cout << b-a;
    }

}
