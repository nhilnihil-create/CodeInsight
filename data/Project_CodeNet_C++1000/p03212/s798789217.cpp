#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;

typedef pair<ll,int>pa;

queue<pa>q;
map<ll,int>mp;


bool check(int x)
{
     int three=0,five=0,seven=0;

     while(x){
        if(x%10==3) three++;
        if(x%10==7) seven++;
        if(x%10==5) five++;
        x/=10;
     }
     if(three && seven && five) return true;
     return false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    int ans=0;
    ll n;cin>>n;
    q.push({0,0});
    while(q.size()){
         pa k=q.front();q.pop();
         ll kk=k.first*10+3;
         if(kk<=n && !mp[kk]) {

            mp[kk]++;
            if(k.second || check(kk)) ans++,q.push({kk,1});
            q.push({kk,0});
         }
         kk=k.first*10+5;
         if(kk<=n && !mp[kk]){

            mp[kk]++;
            if(k.second || check(kk)) ans++,q.push({kk,1});
            q.push({kk,0});
         }
         kk=k.first*10+7;
         if(kk<=n && !mp[kk]){
            mp[kk]++;
           if(k.second || check(kk)) ans++,q.push({kk,1});
           q.push({kk,0});
         }

    }
    cout<<ans<<endl;
     return 0;
}
