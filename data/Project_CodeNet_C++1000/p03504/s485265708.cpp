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
    int n,C;cin>>n>>C;
    vin time(100050);
    vvin start(C,vin(100050)),finish(C,vin(100050));
    int s,t,c;
    rep(i,n){
        cin>>s>>t>>c;
        time[s]++;
        time[t+1]--;
        start[c-1][s]++;
        finish[c-1][t]++;
    }
    rep(i,100020)time[i+1]+=time[i];
    int sum;
    rep(i,100020){
        sum=0;
        rep(j,C)sum+=min(start[j][i],finish[j][i]);//同チャンネルならs==tでも被りとはならない。
        time[i]-=sum;
    }
    sort(all(time));
    reverse(all(time));
    cout<<time[0]<<endl;
}