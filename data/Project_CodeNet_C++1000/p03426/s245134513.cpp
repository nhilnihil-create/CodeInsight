#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    lli h,w,d;
    cin>>h>>w>>d;
    map<lli,pii> ma,prev;
    vi cost(h*w+10);
    rep(i,h)rep(j,w){
        lli k;
        cin>>k;
        ma[k]=pii(i+1,j+1);
    }
    int q;
    cin>>q;
    for(lli i=h*w;i>0;i--){
        if(i+d>h*w) cost[i]=0;
        else{
            cost[i]=cost[i+d]+abs(ma.at(i).first-ma.at(i+d).first)+abs(ma.at(i).second-ma.at(i+d).second);
        }
    }
    rep(i,q){
        lli l,r;
        cin>>l>>r;
        out(cost[l]-cost[r]);
    }
}