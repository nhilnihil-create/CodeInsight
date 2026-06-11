#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main(){
    string s;cin >>s;
    int k;cin >>k;
    ll num=0;
    int i=0;
    char ans;
    while(num<k){
        if(s[i]=='1')num++;
        else num+=INFll;
        ans=s[i];
        i++;
    }
    cout <<ans <<endl;
}
