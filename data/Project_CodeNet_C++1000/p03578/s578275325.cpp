#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    rep(i,n){
        int d;
        cin>>d;
        mp[d]++;
    }
    int m;
    cin>>m;
    vector<int> t(m);
    rep(i,m) cin>>t[i];

    rep(i,m){
        if(mp[t[i]]==0){
            cout<<"NO"<<endl;
            return 0;
        }

        mp[t[i]]--;
    }

    cout<<"YES"<<endl;
}

