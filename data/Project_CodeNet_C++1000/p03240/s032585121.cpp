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
#define _GLIBCXX_DEBUG
const int inf=1e9+7;

int main(){
    int n;cin>>n;
    vin x(n),y(n),h(n);
    rep(i,n)cin>>x[i]>>y[i]>>h[i];
    int tmp;
    bool can;
    rep(i,101)rep(j,101){
        rep(k,n){
            if(h[k]>0){
                tmp=h[k]+abs(x[k]-i)+abs(y[k]-j);
                break;
            }
        }
        can=true;
        rep(k,n){
            if(h[k]!=max(tmp-abs(x[k]-i)-abs(y[k]-j),0)){
                can=false;
                break;
            }
        }
        if(can){
            cout<<i<<" "<<j<<" "<<tmp<<endl;
            return 0;
        }
    }
}