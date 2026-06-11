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
    ll n;cin >>n;
    string ans="";
    ll k=2;
    ll t=0;
    if(n==0)ans+='0';
    while(n!=0){
//        cout<<n%2<<endl;
        if(n%2!=0){
            ans+='1';
//            cout<<n%2<<endl;
            if(t%2==0){
                n--;
            }
            else {
                n++;
            }
        }
        else {
            ans+='0';
        }
        n/=2;
        t++;
    }
    reverse(all(ans));
    cout <<ans <<endl;
    return 0;
}