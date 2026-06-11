#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

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
    int Q;
    cin >> Q;
    sieve(100100);
    vector<int> Csum(100100);
    vector<bool> Is2017(100100,false);
    for(int i=1;i<=100000;i++){
        if(i%2==1&&IsPrime[i]&&IsPrime[(i+1)/2]){
            Is2017[i]=true;
        }
    }
    for(int i=1;i<=100000;i++){
        if(Is2017[i]){
            Csum[i] = Csum[i-1]+1;
        }else{
            Csum[i] = Csum[i-1];
        }
    }
    rep(i,Q){
        int l,r;
        cin >> l >> r;
        
        cout << Csum[r] - Csum[l-1] << endl;
    }
    return 0;
}