// ABC126-D
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

int n=100000;
vector<vector<ipair>> rinsetu(n+1);
vector<int> jisu(n+1,0);
vector<int> color(n+1,-1);
void dfs(int x){
    for(int i=0;i<jisu[x];i++){
        ipair q=rinsetu[x][i];
        int next=q.first,dis=q.second;
        if(color[next]>=0) continue;
        if(dis%2==0){
            color[next]=color[x];
        }else color[next]=1-color[x];
        dfs(next);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int nn;
    cin>>nn;
    rep(i,nn-1){
        int u,v,w;
        cin>>u>>v>>w;
        rinsetu[u].e_b(ipair(v,w));
        rinsetu[v].e_b(ipair(u,w));
        jisu[u]++;
        jisu[v]++;
    }
    color[1]=0;
    dfs(1);
    for(int i=1;i<=nn;i++){
        cout<<color[i]<<endl;
    }
    return 0;
}