#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , int> P;
typedef pair<ll, ll> PL;
const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

bool SecondCompare(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
 
bool SecondCompareDes(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}
 
ll n,p,pp;
string s;
ll cou[1000000];
vector<ll> sosu;
ll a[1000001];
int main(){
    cin >> n >> p;
    if(n == 1){
           cout << p << endl;
           return 0;
    }
    pp = p;

       for(int i = 0; i < 1000000; i++)   a[i] = 1;

    for(int i = 2; i < 1000000; i++){
           if(a[i] == 1){
              sosu.push_back(i);
              for(int j = 0; i * (j+2) < 1000000; j++){
                     a[i*(j+2)] = 0;
              }
           }
    }
    ll mem;

    for(int i = 0; i < sosu.size(); i++){
           mem = 0;
           if(p > 1){
                  while(true){
                         if(p % sosu[i] != 0)    break;
                         p /= sosu[i];
                         ++cou[i];
                  }
           }
           else{
                  break;
           }
    }
    ll ans = 1;
    for(int i = 0; i < sosu.size(); i++){
           if(cou[i] >= n){
                  for(int j = 0; j < cou[i]/n; j++){
                         ans *= sosu[i];
                  }
           }
    }
    cout << ans << endl;
}