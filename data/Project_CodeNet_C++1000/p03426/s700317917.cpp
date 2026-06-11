#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int h,w,d;cin>>h>>w>>d;
    map<int,pair<int,int>> num;
    int a;
    rep(i,h)rep(j,w){
        cin>>a;
        num[a]=mp(i+1,j+1);
    }
    vin power(h*w+1);
    rep2(i,1,d+1){
        power[i]=0;
        for(int j=i+d;j<h*w+1;j+=d){
            power[j]=power[j-d]+abs(num[j].first-num[j-d].first)+abs(num[j].second-num[j-d].second);
        }
    }
    int q;cin>>q;
    int l,r;queue<ll> ans;
    rep(i,q){
        cin>>l>>r;
        ans.push(power[r]-power[l]);
    }
    while(ans.size()){
        cout<<ans.front()<<endl;
        ans.pop();
    }
}