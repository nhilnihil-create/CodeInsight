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

int find_root(vector<int> &parent, int i){
    vector<int> path_nodes;
    int temp=i;
    while(true){
        if(parent[temp] == temp){
            for(int k=0;k<path_nodes.size();k++){
                parent.at(path_nodes.at(k))=temp;
            }
            return temp;
        }else{
            path_nodes.push_back(temp);
            temp=parent[temp];
        }
    }
}

signed merge_trees(vector<int> &parent,int i, int j, vector<int> &tree_size){
    int i_root = find_root(parent, i);
    int j_root = find_root(parent, j);
    if(i_root==j_root){
        return 0; // do nothing
    }else{
        int i_size = tree_size.at(i_root);
        int j_size = tree_size.at(j_root);
        if((i+j)%2==0){
            parent.at(i_root) = j_root;
            tree_size.at(j_root) = tree_size.at(j_root) + tree_size.at(i_root);
        }else{
            parent.at(j_root) = i_root;
            tree_size.at(i_root) = tree_size.at(j_root) + tree_size.at(i_root);
        }
        return j_size*i_size;
    }
}


signed main(){
    int N, M; cin>>N>>M;
    vec_int A(M),B(M);
    rep(i,M){
        cin>>A.at(i)>>B.at(i);
    }

    vec_int unionfind(N+1);
    rep(i,N+1){
        unionfind.at(i) = i;
    }

    vec_int tree_size(N+1);
    rep(i,N+1){
        tree_size.at(i) = 1;
    }

    vec_int ans(M+1);
    ans[M] = (N-1)*N/2;
    for(int i=M-1;i>=0;i--){
        int a = A.at(i);
        int b = B.at(i);
        int temp = merge_trees(unionfind, a,b, tree_size);
        ans.at(i)= ans.at(i+1)-temp;
    }

    for(int i=1;i<M+1;i++){
        cout<<ans.at(i)<<endl;
    }
        


    



    return 0;
}