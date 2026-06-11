#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1000000007;
#define rep(i,n) for(long long i=0;i<(n);i++)
#define rep2(i,m,n) for(long long i=(m);i<(n);i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back







int main(){

    int n;
  	cin>>n;

    vi value(n);
    rep(i,n){
        cin>>value.at(i);
    }
    vi cost(n);
    rep(i,n){
        cin>>cost.at(i);
    }

    int ans=0;

    rep(i,n){
        if (value.at(i)-cost.at(i)>0){
            ans+=value.at(i)-cost.at(i);
        }
    }

    cout<<ans<<endl;

}








            




