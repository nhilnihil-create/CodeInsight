#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<n;i++)

class union_find{
private:
    vector<int>parent;
    vector<int>rank;
    int cnt;
public:
    union_find(int vertex_num){
        parent.resize(vertex_num);
        rank.resize(vertex_num);
        cnt=vertex_num;
        rep(i,vertex_num){
            parent[i]=i;
            rank[i]=0;
        }   
    }
    int get_root(int n /*知りたい根の頂点の番号*/){
        if(parent[n]==n){
            return n;
        }else{
            return get_root(parent[n]);
        }
    }
    bool is_same(int a,int b /*連結を判定したい2頂点*/){
        return get_root(a) == get_root(b);
    }

    void unite(int a,int b){
        int root_a=get_root(a);
        int root_b=get_root(b);
        if(root_a==root_b)return;

        if(rank[root_a]<rank[root_b]){
            parent[root_a]=root_b;
            cnt--;
        }else if(rank[root_a]>rank[root_b]){
            parent[root_b]=root_a;
            cnt--;
        }else{
            parent[root_a]=root_b;
            ++rank[root_b];
            cnt--;
        }
    }
    int ans(){
        return cnt;
    }

};

signed main(){
    ll n,m,ans=0;
    cin>>n>>m;
    //vector<pair<int,int>>ab(n);
        int a[m],b[m];
    rep(i,m){
        cin>>a[i]>>b[i];
        //ab[i]=make_pair(a,b);
        
    }
    rep(i,m){
        union_find uf(n);
        rep(j,m){
            if(i==j)continue;
            uf.unite(a[j],b[j]);
        }
        if(uf.ans()!=1)ans++;   
    }
    cout<<ans<<endl;

       
}
/*
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
*/
