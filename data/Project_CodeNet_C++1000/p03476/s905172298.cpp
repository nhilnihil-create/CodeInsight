#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    
   int Q;
   cin>>Q;
   vector<int> l(Q), r(Q);
   rep(i,Q) cin>>l[i]>>r[i];

   int MAX = 100100;
   //エラストテネスの篩
   vector<int> is_prime(MAX, 1);
   is_prime[0]=0;
   is_prime[1]=0;
   for(int i=2;i<MAX;i++){
       //素数でない判定されたものは無視
       if(!is_prime[i]) continue;
       //素数判定されたものの倍数は無視
       for(int j=i*2;j<MAX;j+=i) is_prime[j]=0;
   }
   //2017に似た数かどうか
   vector<int> num(MAX, 0);
   for(int i=0;i<MAX;i++){
       //偶数は対象でない
       if(i%2==0) continue;
       if(is_prime[i] && is_prime[(i+1)/2]) num[i]=1;
   }
   
   //累積和、最大値MAX分前処理
   vector<int> sum(MAX+1, 0);
   rep(i,MAX){
       sum[i+1] = sum[i]+num[i];
   }

   rep(i,Q){
       cout<<sum[r[i]+1]-sum[l[i]]<<endl;
   }


    return 0;
}
