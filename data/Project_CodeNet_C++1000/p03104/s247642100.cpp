#include <bits/stdc++.h>
using namespace std;

long long A[200], B[200];

long long _log2(long long b){
    long long ans = 0;
    while(b > 0){
        ans++;
        b /= 2;
    }
    return ans-1;
}

long long _pow2(long long b){
    long long ans = 1;
    for(int i = 0; i < b; i++)
        ans *= 2;
    return ans;
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    if(a > b) swap(a, b);
    a = max(a-1, 0LL);
    long long addA = 0, addB = 0;
    while(a > 0){
        long long right = a ^ (a & (a-1));
        a = (a & (a-1));
        for(int i = 0; i < _log2(right); i++){
            A[i] += right/2;
        }
        A[_log2(right)] += 1;
        A[_log2(right)] += addA;
        addA += right;

    }
    while(b > 0){
        long long right = b ^ (b & (b-1));
        b = (b & (b-1));
        for(int i = 0; i < _log2(right); i++){
            B[i] += right/2;
        }
        B[_log2(right)] += 1;
        B[_log2(right)] += addB;
        addB += right;
    }

    for(int i = 0; i < 50; i++){
        if( (B[i]-A[i]) % 2 == 1)
            ans = ans | _pow2(i);
    }
    cout << ans << "\n";
}
