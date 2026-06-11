#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);

    rep(i,n){
        int p;
        cin>>p;
        p--;
        v[p]=i;
    }

    //rep(i,n) cout<<v[i]<<" ";
    //cout<<endl;

    int ans=1,tmp=1;
    rep(i,n-1){
        if(v[i]<v[i+1]){
            tmp++;
            ans=max(ans,tmp);
        }
        else{
            tmp=1;
        }
    }   

    cout<<n-ans<<endl;
}