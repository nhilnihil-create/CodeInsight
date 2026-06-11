#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll n;cin>>n;
   vector<ll>a(n);
   vector<ll>b(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >>b[i];
    }
   vector<ll>d(n);
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        d[i]=a[i]-b[i];
        sum+=d[i];
    }
   if(sum<0)cout <<-1<<endl;
   else {
       vector<bool>ch(n,true);
       ll ans=0;
       sort(all(d));
       ll k=n-1;
       for (int i = 0; i < n; ++i) {
           if(d[i]<0){
               if(ch[i])ans++;
               ch[i]=false;
               while(1) {
                   if (d[k] + d[i] < 0) {
                       if (ch[k]) {
                           ans++;
                           ch[k] = false;
                       }
                       d[i] += d[k];
                       d[k] = 0;
                       k--;
                   }
                   else {
                       if(ch[k]){
                           ans++;
                           ch[k]=false;
                       }
                       d[k]+=d[i];
                       d[i]=0;
                       break;
                   }
               }
           }
       }
       cout <<ans <<endl;
   }
   return 0;
}