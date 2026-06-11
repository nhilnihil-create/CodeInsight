#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<ll> memo(100);

ll fib(ll n){
    if(memo[n] == -1) {
        memo[n] = fib(n - 1) + fib(n - 2);
    }
    return memo[n];
}

int main(){
    for(int i=0;i<100;i++){
        memo[i] = -1;
    }
    memo[0] = 2;
    memo[1] = 1;

    ll n;
    cin >> n;
    cout << fib(n) << endl;
}
