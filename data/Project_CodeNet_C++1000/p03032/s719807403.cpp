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
    int n,k;cin>>n>>k;
    vin v(n);rep(i,n)cin>>v[i];
    int sum,tmp;int m=0;
    rep(i,k+1){//i回取り出す→最大でmin(i,k-i)個しまう
        rep(j,i+1){//左端からj個取り出す
            vin jew;sum=0;
            rep(l,min(j,n)){
                jew.push_back(v[l]);
                sum+=v[l];
            }
            for(int l=n-1;l>=max(j,n-i+j);l--){
                jew.push_back(v[l]);
                sum+=v[l];
            }
            sort(all(jew));
            tmp=jew.size();
            rep(l,min(tmp,min(i,k-i)))if(jew[l]<0)sum-=jew[l];
            m=max(m,sum);
        }
    }
    cout<<m<<endl;
}