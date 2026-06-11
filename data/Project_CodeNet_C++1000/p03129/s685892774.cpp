#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
using  namespace std;

typedef long long ll;
vector<ll> fib;

ll fibo(ll n){
    if (n <= 1) {
        return n;
    }

    if (fib[n] != 0) {
        return fib[n];
    }

    return fib[n] = fibo(n-1) + fibo(n-2);
}

int main(int argc, char const* argv[])
{
    int N, K;
    cin >> N >> K;

    if ((N + 1) / 2 >= K) {
        cout << "YES" << endl;
    }else{
        cout << "NO" <<endl;
    }

    return 0;
}
