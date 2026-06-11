#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb push_back;
#define sp " ";
#define INF=200000000;
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
vi par(1000000);/*親*/
vi hukasa(1000000);/*根の深さ*/
void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        hukasa[i]=0;
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
    if(hukasa[x]<hukasa[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(hukasa[x]=hukasa[y]) hukasa[x]++;
    }
}
/*同じ集合に属するか調べる*/
bool same(int x,int y){
    return find(x)==find(y);
}
/*利用方法はparのそれぞれの要素に対応させる形で別の配列を用意し、そこに入力する。*/
int main(){
    int n,m;
    cin>>n>>m;
    init(n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        unite(x,y);
    }
    set<int> p;
    rep(i,n){
        if(!p.count(find(i))){
            p.insert(find(i));
        }
    }
    cout<<p.size();

}