// ABC79-D      
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define e_b emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
void map_p(map<int,int>& d){cout<<"map: ";for(auto a : d){cout<<"{"<<a.first<<":"<<a.second<<"}";}cout<<endl;} //mapの中身を見る
void set_p(set<int>& d){cout<<"set: ";for(int a : d){cout<<a<<" ";}cout<<endl;} //setの中身を見る


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    
    vector<vector<int>> dp(10,vector<int>(10,0));
    int h,w;
    cin>>h>>w;
    rep(i,10){
        rep(j,10){
            cin>>dp[i][j];
        }
    }
    for(int k=0;k<=9;k++){
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    ll ans=0;
    rep(i,h){
        rep(j,w){
            int now;
            cin>>now;
            if(now==-1) continue;
            ans+=dp[now][1];
        }
    }
    cout<<ans<<endl;
    return 0;
}