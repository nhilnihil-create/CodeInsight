#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}
int main() {
    long long N,M;
    string S,T;
    cin >> N >> M;
    cin >> S;
    cin >> T;
    long long g = gcd(N,M);
    long long n = N/g;
    long long m = M/g;
    bool flag = true;
    for(long long i = 0; i < g;i++){
        if(S[i*n]!=T[i*m])flag = false;
    }
    if(flag)cout << lcm(N,M)<<endl;
    else cout << -1 << endl;
    
}