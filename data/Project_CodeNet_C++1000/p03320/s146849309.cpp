#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long s(long long n){
    long long res = 0;
    for(; n > 0; n /= 10) res += n%10;
    return res;
}

bool comp(const long long &a, const long long &b){
    long long ta = a * s(b);
    long long tb = b * s(a);
    if(ta == tb) return a < b;
    return ta < tb;
}

long long f(long long n){
    vector<long long> v;
    for(long long i=1;i<=n;i*=10){
        v.push_back(n - n%i + i - 1);
    }
    sort(v.begin(), v.end(), comp);
    return v[0];
}

int main(void){
    int k;
    long long n = 1;
    cin >> k;
    for(int i=0;i<k;i++){
        cout << n << endl;
        n = f(n+1);
    }
}
