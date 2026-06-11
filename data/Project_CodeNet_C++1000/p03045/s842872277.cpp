#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set> 
using namespace std;

struct UnionFind{
    vector<int> branch;
    UnionFind(int N=0):branch(N,-1){}
    int find(int x){
        if(branch[x]<0){
            return x;
        }
        else{
            return branch[x]=find(branch[x]);//メモ化、要素を入れて根が返ってくる    
        }
    }
    bool unite(int x, int y){
        int rx,ry;
        rx=find(x);
        ry=find(y);
        if(rx==ry){
            return false;//連結できたかどうかが大事なこともあるらしい
        }
        if(-branch[rx]<-branch[ry]){//bramch[rx]を常に大きい方にする
            swap(rx,ry);    
        }
        branch[rx]+=branch[ry];//木のサイズを負の値で管理
        branch[ry]=rx;
        return true;
    }
    bool same(int x, int y){
        if(find(x)==find(y)){
            return true;
        }
        else{
            return false;
        }
    }
    int size(int x){
        return -branch[find(x)];
    }
};

    
int main(){
    int n,m;
    cin >> n >> m;
    UnionFind tree(n);
    set<int> st;
    for(int i = 0; i < m; i++){
        int x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        tree.unite(x,y);
    }
    for(int i = 0; i < n; i++){
        st.insert(tree.find(i));
    }
    cout << st.size() << endl; 
}