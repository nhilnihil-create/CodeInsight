#include<bits/stdc++.h>

using namespace std;
using ll = long long;

class UnionFind{
  private:
    vector<int> data; //data[i] : 頂点i
  public:

    UnionFind(int n) : data(n,-1) {}
    int root(int i) { return data[i] < 0 ? i : data[i] = root(data[i]); }
    int size(int i) { return -data[root(i)]; }
    bool same(int x, int y) {return root(x) == root(y); }
    bool connected() {return size(0) == (int)data.size(); }
    

    bool unit(int i,int j){
        i = root(i);
        j = root(j);
        if(i != j){
            data[i] += data[j];
            data[j] = i;
        }
        return i != j;
    }

};

int main()
{
    int n, m; cin >> n >> m;
    UnionFind tree(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        tree.unit(x - 1, y - 1);
    }
    set<int> st;
    for(int i = 0; i < n; i++)st.insert(tree.root(i));
    cout << st.size() << endl;
}