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
    int n,x;cin >>n>>x;
    int ans=0;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        x-=a[i];
        if(x<0)break;
        ans++;
        if(i==n-1&&x!=0)ans--;
    }
    cout << ans <<endl;
}
