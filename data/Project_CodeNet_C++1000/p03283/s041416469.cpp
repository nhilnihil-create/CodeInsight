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
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int N,M,Q;cin>>N>>M>>Q;
    vvin train(N+1,vin(N+1));
    int L,R;
    rep(i,M){
        cin>>L>>R;
        train[L][R]++;
    }
    rep2(i,1,N+1)rep2(j,i,N+1)train[i][j]+=train[i][j-1];
    queue<int> que;
    int p,q,sum;
    rep(i,Q){
        cin>>p>>q;
        sum=0;
        rep2(j,p,q+1)sum+=train[j][q];
        que.push(sum);
    }
    while(que.size()){
        cout<<que.front()<<endl;
        que.pop();
    }
}