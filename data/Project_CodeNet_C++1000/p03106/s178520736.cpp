#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;


void solve(long long A, long long B, long long K){

    if(A<B){
        ll tmp = A;
        A = B;
        B = tmp;
    }
    ll r = B;
    ll count =0;
    while(r>0){
        if(A%r==0 && B%r==0){
            count++;
        }
        if(count==K){
            cout << r << endl;
            return;
        }
        r--;
    }
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long K;
    scanf("%lld",&K);
    solve(A, B, K);
    return 0;
}
