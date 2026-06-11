#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

// 0~AまでのXOR
ll F(ll A){
    ll res;
    if(A%2==1){
        if((A+1)/2 % 2 == 0){
            res = 0;
        }else{
            res = 1;
        }
    }else{
        res = F(A+1)^(A+1);
    }
    return res;
}

int main(){
    ll A,B;
    cin >> A >> B;
    cout << (ll)(F(A-1)^F(B)) << endl;
    return 0;
}