#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;
typedef pair<int,int> P;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

struct UnionFind{
    vector<int> parent;
    vector<int> sizes;
    UnionFind(int n){
        parent.resize(n);
        sizes.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    int root(int s){
        if(parent[s] == s) return s;
        return root(parent[s]);
    }

    void unionf(int s,int t){
        int rs = root(s);
        int rt = root(t);
        if(rs == rt) return;
        if(sizes[rs] >= sizes[rt]){
            parent[rt] = rs;
            sizes[rs] += sizes[rt];
        }
        else{
            parent[rs] = rt;
            sizes[rt] += sizes[rs];
        }
    }

    int size(int s){
        return sizes[root(s)];
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<P> r(M);
    UnionFind uf(N);
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        r[i] = make_pair(a,b);
        uf.unionf(a,b);
    }
    int count = 0;
    for(int i = 0; i < M; i++){
        UnionFind uftemp(N);
        for(int j = 0; j < M; j++){
            if(i == j) continue;
            int a = r[j].first;
            int b = r[j].second;
            uftemp.unionf(a,b);
        }
        if(uftemp.size(0) != N) count++;
    }
    cout << count << endl;
    return 0;
}
