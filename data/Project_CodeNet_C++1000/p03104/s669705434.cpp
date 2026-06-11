#include <bits/stdc++.h>
#include <math.h>
#define INF 10000000000
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pa;


long long odd_xor(ll a){
    if ((a+1)/2 % 2 == 1){
        return 0;
    }else{
        return 1;
    }
}

long long even_xor(ll a){
    return odd_xor(a+1)^(a+1);
}

ll calc_xor(ll a){
    if (a % 2 == 1){
        return odd_xor(a);
    }
    else{
        return even_xor(a);
    }
}


int main(){

    ll A, B;
    cin >> A >> B;
    cout << (calc_xor(B) ^ calc_xor(A-1)) << endl;
}