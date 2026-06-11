#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int find_root(int i, vec_int &UF_tree){
    vec_int route_nodes;
    int node = i;
    while(true){
        route_nodes.push_back(node);
        int parent = UF_tree.at(node);
        if(parent == node){
            break;
        }
        node = parent;
    }
    for(auto aa: route_nodes){
        UF_tree.at(aa) = node;
    }

    return node;
}

void merge_trees(int node_i, int node_j, vec_int& UF_tree){
    // node i と jの所属する木をくっつける
    // それぞれのrootを探してきて、片っぽのrootをもう片っぽのrootに付け替える
    int root_i = find_root(node_i, UF_tree);
    int root_j = find_root(node_j, UF_tree);

    if(node_i%2==0){
        UF_tree.at(root_j) = root_i;
    }else{
        UF_tree.at(root_i) = root_j;
    }
}

signed main(){
    int N, M; cin>>N>>M;
    vec_int X(M), Y(M),Z(M);
    rep(i,M)cin>>X.at(i)>>Y.at(i)>>Z.at(i);

    vec_int UF_tree(N+1);
    rep(i,N+1)UF_tree.at(i) = i;

    for(int i=0;i<M;i++){
        merge_trees(X.at(i),Y.at(i),UF_tree);
    }

    for(int i=0;i<N;i++){
        int temp = find_root(i+1,UF_tree);
    }
    set<int> out_set;
    for(int i=0;i<N;i++){
        out_set.insert(UF_tree.at(i+1));
    }
    cout<<out_set.size()<<endl;




    // これは雰囲気union-find系の問題だな
    // X, Yの組になっている数値は片っぽがわかればもう片っぽは瞬時にわかる 
    // union-findでくっつけていって、





    return 0;
}