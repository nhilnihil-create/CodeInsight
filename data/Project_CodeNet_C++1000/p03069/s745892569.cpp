#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> whsum(n+1,0);
    vector<int> blsum(n+1,0);
    rep(i,n){
        whsum[i+1]=whsum[i]+(s[i]=='.' ? 1 : 0);
        blsum[i+1]=blsum[i]+(s[i]=='#' ? 1 : 0);
    }

    ll res=1LL<<60;
    for(int left=0;left<=n;left++){
        ll tmp=0;
        tmp+=blsum[left]-blsum[0];
        tmp+=whsum[n]-whsum[left];

        res=min(res,tmp);
    }

    cout<<res<<endl;
}
