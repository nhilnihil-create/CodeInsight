#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
typedef long long int ll;
const ll INF=1e11;
int par[100000]; //親
ll diff_weight[100000];
int height[100000];  //木の深さ

void init (int n){
    for (int i=0;i<n;i++){
        par[i]=i;
        height[i]=0;
        diff_weight[i]=0;
    }
}
int find (int x){
    if (par[x]==x){
        return x;
    }
    else{
        int f=find(par[x]);
        diff_weight[x]+=diff_weight[par[x]];
        return par[x] = f;
    }
}
ll weight(int x){
    find(x);
    return diff_weight[x];
}
bool unite (int x, int y,ll w){
    w+=weight(x);
    w-=weight(y);
    x=find(x);
    y=find(y);
    if (x==y) return false;
    if (height[x] < height[y]){
        swap(x,y);
        w=-w;
    }
    if (height[x]==height[y]) {
        height[x]++;
    }
        par[y]=x;
        diff_weight[y]=w;
        return true;
}

bool same (int x, int y){
    return find(x) == find(y);
}
ll diff(int x, int y){
    return weight(y)-weight(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    if (M==0) cout <<"Yes"<<"\n";
    else {
        init (N);
        rep(i,0,M){
            int l,r,d;
            cin>>l>>r>>d;
            l--; r--;
            if (same(l,r)){
                if (diff(l,r)!=d){
                    cout << "No" <<"\n";
                    return 0;
                }
            }
            else {
                unite(l,r,d);
            }
        }
        cout <<"Yes"<<"\n";
    }
}