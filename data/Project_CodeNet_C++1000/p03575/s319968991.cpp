#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

class UnionFind{
public:
    vector<int> v;
    UnionFind(int size):v(size,-1){}

    int root(int a){
        if(v[a]<0){
            return a;
        }else{
            int res=root(v[a]);
            v[a]=res;
            return res;
        }
    }

    void unite(int a,int b){
        int roota=root(a);
        int rootb=root(b);
        if(roota==rootb){return;}
        if(v[roota]>v[rootb]){
            v[rootb]+=v[roota];
            v[roota]=rootb;
        }else{
            v[roota]+=v[rootb];
            v[rootb]=roota;
        }
    }

    bool same(int a,int b){
        return root(a)==root(b);
    }

    int size(int a){
        return v[root(a)];
    }
};

int main(){
    int N,M;
    cin>>N>>M;

    vector<pair<int,int>> E;
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        E.push_back({a,b});
    }

    //cout<<"hoge"<<endl;

    int ans=0;
    for(int i=0;i<M;i++){
        //cout<<i<<endl;
        UnionFind uf(N+1);
        for(int j=0;j<M;j++){
            if(j!=i){
                uf.unite(E[j].first,E[j].second);
            }
        }

        int cnt=0;
        for(int j=1;j<=N;j++){
            if(uf.v[j]<0){
                cnt++;
            }
        }

        if(cnt>1){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}