// ABC120-D
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

struct unionfind{
    vector<int> par;
    void init(int n){
        par.assign(n,-1);
    }
    int find(int x){
        if(par[x]<=-1) return x;
        par[x]=find(par[x]);
        return par[x];
    }
    int size(int x){
        return -1*par[find(x)];
    }
    void unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return;
        if(size(x)<size(y)) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
    }
    bool same_set(int x,int y){
        return find(x)==find(y);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll n,m;
    cin>>n>>m;
    unionfind uf;
    uf.init(n);
    vector<ipair> hen(m);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        --a,--b;
        hen[i]=ipair(a,b);
    }
    ll huben=n*(n-1)/2;
    vector<ll> ans(m+1);
    ans[m]=huben; 
    for(int i=m-1;i>=0;i=i-1){ //m-1番目の辺から足していく
        ipair cur=hen[i];
        int ca=cur.first,cb=cur.second;
        if(uf.same_set(ca,cb)){ //合体するsetがもともと同じset
            ans[i]=huben;
            continue;
        }
        ll set1_size=uf.size(ca),set2_size=uf.size(cb);
        huben=huben-set1_size*set2_size;
        ans[i]=huben;
        uf.unite(ca,cb);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    return 0;
}