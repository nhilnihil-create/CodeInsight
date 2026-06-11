#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
using namespace std;


int main() {
    ll A,B,K;
    cin >> A >> B >> K;
    for (int i = 0; i < K; i++)
    {
        if(A+i <= B) cout << A+i << endl;
    }
    for (int i = 0; i < K; i++)
    {
        if(B-K+1+i > A+K-1) cout << B-K+1+i << endl;
    }
    
}