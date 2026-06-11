#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


void solve(long long A, long long B, long long C){
    if(A*C <= B){
        cout << C << endl;
    } else {
        cout << B / A << endl;
    }
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    solve(A, B, C);
    return 0;
}
