#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UF {
public:
    int par[100000];
    int _size[100000];
    UF(int n) {
        for (int i=0;i<n;i++) {
            par[i]=i;
            _size[i]=1;
        }
    }
    int find(int n) {
        if (par[n]==n)
            return n;
        return par[n]=find(par[n]);
    }
    void unite(int a,int b) {
        a=find(a);
        b=find(b);
        if (a==b)
            return;
        par[b]=a;
        _size[a]+=_size[b];
    }
    int size(int n) {
        return _size[find(par[n])];
    }
};

int main() {
    int n,m;cin>>n>>m;
    pair<int,int> e[m];
    UF uf(n);
    for (int i=0;i<m;i++) {
        int a,b;cin>>a>>b;a--,b--;
        e[i]={a,b};
    }
    ll ans[m];
    ans[m-1]=(ll)n*(n-1)/2;
    for (int i=m-1;i>=1;i--) {
        ans[i-1]=ans[i];
        int a=e[i].first,b=e[i].second;
        if (uf.find(a)!=uf.find(b))
            ans[i-1]-=uf.size(a)*uf.size(b);
        uf.unite(a,b);
    }
    for (int i=0;i<m;i++)
        cout<<ans[i]<<endl;
    return 0;
}