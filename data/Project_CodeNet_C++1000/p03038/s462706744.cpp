#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define ll long long
         
using namespace std;
     
long long gcd(int x, int y){
     if ( x == 0 ) return y;
     
     return gcd(y%x, x);
}
     
long long lcm(int x, int y){
     if ( y == 0 ){
          return x;
     }
     
     return x*y/gcd(x, y);
}
     
ll min(ll a, ll b){
     return a > b ? b : a;
}
     
ll max(ll a, ll b){
     return a > b ? a : b;
}

int main()
{
     cin.sync_with_stdio( false );
     
     int n,m;
     cin>>n>>m;
     
     priority_queue <ll, vector <ll>, greater<ll> > q;
     map <ll, ll> rep;
     vector <pair<ll ,ll> > arr(m);
     
     for (int i=0;i<n;i++){
         ll qq;
         cin>>qq;
         
         q.push(qq);
         rep[qq]++;
     }
     
     for (int i=0;i<m;i++){
         //ll a,b;
         //cin>>a>>b;
         cin>>arr[i].second>>arr[i].first;
         
         //arr.push_back({b, a});
     }
     
     sort(arr.begin(), arr.end());
     reverse(arr.begin(), arr.end());
     
     for (int i=0;i<m;i++){
         ll a = arr[i].second;
         ll b = arr[i].first;
         while ( a > 0 ){
             ll qq = q.top();
             //q.pop();
             if ( qq >= b ){
                 break;
             }else{
                 ll smanji = min(rep[qq], a);
                 rep[qq]-=smanji;
                 rep[b]+=smanji;
                 a-=smanji;
                 q.push(b);
                 
                 if ( rep[qq] == 0 ){
                     q.pop();
                     rep.erase(qq);
                 }
             }
         }
     }
     
     ll res = 0;
     for (auto i:rep){
         res+=i.first*i.second;
     }
     
     cout<<res<<endl;
}