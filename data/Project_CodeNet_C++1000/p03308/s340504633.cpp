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
   vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(all(a));
    cout <<a[n-1]-a[0]<<endl;
   return 0;
}