#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<pair<long long,long long> >prime_factorize(long long N){
    vector<pair<long long, long long>> res;
    for(long long a=2;a*a<=N;a++){
        if(N%a!=0) continue;
        long long ex=0;
        while(N%a==0){
            ex++;
            N /= a;
        }
        res.push_back({a,ex});
    }
    if(N!=1) res.push_back({N,1});
    return res;
}

int main(){
    cin >> n;
    vector<ll> ex(n+1,0);
   for(long long i=2;i<=n;i++){
       const auto &res = prime_factorize(i);
       for(auto p:res) ex[p.first] +=p.second;
   }
   ll count75=0;
   ll count25=0;
   ll count15=0;
   ll count5=0;
   ll count3=0;
   for(ll i=0;i<=n;i++){
       if(ex[i]>=74) count75++;
       if(ex[i]>=24) count25++;
       if(ex[i]>=14) count15++;
       if(ex[i]>=4) count5++;
       if(ex[i]>=2) count3++;
   }
   ll res=count75+count25*(count3-1)+count15*(count5-1)+count5*(count3-2)*(count5-1)/2;
   cout << res << endl;
   return 0;
}  
