#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
T gcd(T a, T b){
    if(b == 0){ return a;}
    else {
        return gcd(b, a % b);
    }
}
template<typename T>
T gcdAll(std::vector<T> & vals){
    int size = vals.size();
    T gcdVal = vals[0];
    for(int i = 1 ; i < size; i++){
        gcdVal = gcd(std::max(vals[i], gcdVal), std::min(vals[i], gcdVal));
    }
    return gcdVal;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll val = gcdAll(A);

    cout << val << endl;

    return 0;
}
