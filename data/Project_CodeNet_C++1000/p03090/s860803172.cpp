#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repp(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define repm(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define INF (1ll<<60)
typedef long long lint;
const lint MOD =1000000007;
const lint MAX = 10000000;

 
lint fac[MAX], finv[MAX], inv[MAX];

void COMinit() // 二項係数を求める時は前処理としてCOMinit()をする
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (lint i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(lint n, lint k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

lint primary(lint num)
{
    if (num < 2) return 0;
    else if (num == 2) return 1;
    else if (num % 2 == 0) return 0; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return 0;
        }
    }

    // 素数である
    return 1;
}

   

int main(){
      lint N;
      cin>>N;
      lint x=N;
    if(N%2==1)x--;
    if(N%2==1)cout<<(x-2)*x/2+x<<endl;
    else cout<<x*(x-2)/2<<endl;
        vector<pair<int,int>> h;
    lint p=x;
    repp(i,1,x+1){
        repp(j,1,x+1){
                if(i==j||j==p)continue;
            h.push_back(make_pair(i,j));
        }
        p--;
    }

    rep(i,h.size()){
        lint f,g;
        tie(f,g)=h[i];
        if(f<=g)cout<<f<<" "<<g<<endl;
    }
    if(N%2==1){
        rep(i,N-1){
            cout<<N<<" "<<i+1<<endl;        
    }
    }
      
}