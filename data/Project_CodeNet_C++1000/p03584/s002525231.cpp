#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n,k; cin>>n>>k; k++;
    vector<P> ab(n);
    rep(i,n)cin>>ab.at(i).F>>ab.at(i).S;

    int ans=0;
    for(int i=30; i>=0; i--){
        int bit=1<<i;
        if(k&bit){
            int sum=0;
            rep(j,ab.size()){
                if(!(ab.at(j).F&bit))sum+=ab.at(j).S;
            }
            chmax(ans,sum);
        }else{
            vector<P> tmp;
            rep(j,ab.size()){
                if(!(ab.at(j).F&bit))tmp.push_back(ab.at(j));
            }
            ab=tmp;
        }
    }
    cout<<ans<<endl;

}