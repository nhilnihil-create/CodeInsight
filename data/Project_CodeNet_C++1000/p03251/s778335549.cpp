#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX
typedef pair<long long, long long> P;
int main(){

    long long n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int> v(n);
    vector<int> w(m);
    rep(i,n){
        cin>>v[i];
    }
    rep(i,m){
        cin>>w[i];
    }
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    if(v[n-1]<w[0]&& v[n-1]<y &&x<w[0]){
        cout<<"No War"<<endl;
    }
    else{
        cout<<"War"<<endl;
    }
    
}
