// CODE FESTIVAL 2017 qual B-C
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

int n_max=100010;
vector<int> color(n_max,-1);
vector<int> jisu(n_max,0);
vector<vector<int>> rinsetu(n_max);
int c_0=0;
bool dfs(int x,int c){
    color[x]=c;
    if(c==0) c_0++;
    for(int i=0;i<jisu[x];i++){
        int next=rinsetu[x][i];
        if(color[next]==-1 && !(dfs(next,1-color[x]))){
            return false;
        }else{
            if(color[x]==color[next]){
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll n,m;
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        jisu[a]++,jisu[b]++;
        rinsetu[a].e_b(b),rinsetu[b].e_b(a);
    }
    if(dfs(1,0)){
        cout<<(c_0*(n-c_0))-m<<endl;
    }else{
        cout<<n*(n-1)/2-m<<endl;
    }
    return 0;
}