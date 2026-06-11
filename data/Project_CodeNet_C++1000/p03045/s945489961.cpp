#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class UF{
private:
    std::vector<long long> data; //data[i] : 頂点iの親
public:
    UF(int n){
        data.resize(n,-1);
    }
    //頂点iの親を返す
    int root(int i){
        if(data[i] < 0)return i;
        else return data[i] = root(data[i]);
    }
    //連結
    void unit(int i,int j){
        i = root(i);j = root(j);
        if(i != j){
            data[i] += data[j];
            data[j] = i;
        }
    }

    //頂点iの属する集合の頂点数
    int size(int i){
        i = root(i);
        return -data[i];
    }
};

int main()
{
    int n, m; cin >> n >> m;
    UF tree(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        tree.unit(x - 1, y - 1);
    }
    set<int> st;
    for(int i = 0; i < n; i++)st.insert(tree.root(i));
    cout << st.size() << endl;
}