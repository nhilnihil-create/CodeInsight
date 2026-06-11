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
    int n;cin >>n;
    int a,b;cin>>a>>b;
    int fi=0,se=0,th=0;
    vector<int>p(n);
    for (int i = 0; i < n; ++i){
        cin >>p[i];
        if(p[i]<=a)fi++;
        else if(p[i]<=b)se++;
        else th++;
    }
    int ans=min({fi,se,th});
    cout <<ans <<endl;
}
