#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int par[200000];/*親*/
int Rank[200000];/*根の深さ*/
/*n要素で初期化*/
void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        Rank[i]=0;
    }
}
/*木の根を求める*/
int find(int x){
    if(par[x]==x){/*親が自分自身＝根*/
        return x;
    }
    else{
        return par[x]=find(par[x]);/*一つ上の階層へ*/
    }
}
/*ｘとｙの集合を併合*/
void unite(int x,int y){
    x=find(x);
    y=find(y);
    /*根を求める*/
    if(x==y) return;/*同じ集合に属していたら終了*/
    if(Rank[x]<Rank[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(Rank[x]==Rank[y]) Rank[x]++;
    }
}
/*同じ集合に属するか調べる*/
bool same(int x,int y){
    return find(x)==find(y);
}
/*利用方法はparのそれぞれの要素に対応させる形で別の配列を用意し、そこに入力する。*/
int main(){
    lli n,m;
    cin>>n>>m;
    init(n+10);
    vector<pii> edge;
    vector<lli> ans;
    map<lli,lli> node;
    rep(i,n){
        node[i+1]=1;
    }
    vector<lli> pole(n,1);
    rep(i,m){
        lli a,b;
        cin>>a>>b;
        edge.push_back(pii(a,b));
    }
    lli time=(node.size()*(node.size()-1))/2;
    ans.push_back(time);
    for(int i=m-1;i>=0;i--){
        lli ca,cb,num,mo;
        ca=find(edge.at(i).first);
        cb=find(edge.at(i).second);
        if(ca==cb) {ans.push_back(time);continue;}
        num=node.at(ca)+node.at(cb);
        time-=node.at(cb)*node.at(ca);
        unite(ca,cb);
        mo=find(ca);
        node.at(mo)=num;
        if(mo==ca){
            node.erase(cb);
        }
        else{
            node.erase(ca);
        }
        ans.push_back(time);
    }
    reverse(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++){
        cout<<ans.at(i)<<endl;
    }
}