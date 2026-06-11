#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
    int n;cin >>n;
    int co=0;
    while(n>0){
        if(n%10==2)co++;
        n/=10;
    }
    cout << co << endl;
    return 0;
}
