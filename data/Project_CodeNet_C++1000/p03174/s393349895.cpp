//
//  main.cpp
//  DPo
#include <iostream>
using namespace std;
using ll = long long;
int a[22][22]={}; // 配列の準備 Nは最大21人
int ds[22]={0}; // 各桁の状態　1か0
int dp[2100000]={0};
bool flag[2100000]={false};
const int mod = 1e9+7;
int f(int n){
    if(n==0) return 1;
    ll mx=n;
    int digit=0;
    int d_sum=0; // 1が何個あるか
    while(mx!=0){
        if(mx%2==1){
            ds[digit+1]=1; // その桁は１
            d_sum++;
        }else{
            ds[digit+1]=0; // その桁は０
        }
        mx=mx>>1;
        digit++; // nを2進数で表現したときの桁
    }
    int sum=0;
    for (int i=1; i<=digit; i++) {
        if(ds[i]==1){
            if(flag[n-(1<<(i-1))]==false){
            sum=(sum+a[d_sum][i]*f(n-(1<<(i-1))))%mod;
            }else{
            sum=(sum+a[d_sum][i]*dp[n-(1<<(i-1))])%mod;
            }
        }
    }
    flag[n]=true;
    return dp[n]=sum%mod;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n; // 男女の人数

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j]; // 相性のデータを読み込んで
        }
    }
    int mx=(1<<n)-1; // 2のn乗-1
    cout<<f(mx)<<endl;
    return 0;
}
