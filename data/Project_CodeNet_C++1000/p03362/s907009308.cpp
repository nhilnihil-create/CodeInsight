#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

vector<bool> IsPrime;
void sieve(ll max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(ll i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(ll j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}



int main(){
    int n;
    cin >> n;
    sieve(55556);
    int cnt = 0;
    rep(i, 55556){
        if (IsPrime[i + 2] && (i + 2) % 5 == 1 && cnt < n){
            cout << i + 2 << " ";
            cnt ++;
        }
    }
    cout << endl;
    return 0;
}