#include <iostream>
#include <vector>
using namespace std;

class union_find{
public:
    union_find(int N){
        parent = new int[N];
        for(int i = 0; i < N; i++) parent[i] = i;
    }

    int root(int x){
        if(parent[x] == x) return x;
        else return (parent[x] = root(parent[x]));
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        parent[y] = x;
    }

private:
    int *parent;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];

    int ans = 0;
    for(int i = 0; i < m; i++){
        union_find data(n+1);
        for(int j = 0; j < m; j++){
            if(j == i) continue;
            data.unite(a[j], b[j]);
        }
        bool islinking = true;
        for(int j = 1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
                if(!data.same(j, k)) islinking = false;
            }
        }
        if(!islinking) ans++;
    }
    cout << ans << endl;
    return 0;
}