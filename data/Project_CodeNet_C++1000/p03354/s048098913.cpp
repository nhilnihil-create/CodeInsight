#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
vector<int> to[200005];
int ans = 0;
class UnionFind
{
public:
    vector<int> Parent;
    UnionFind(int N)
    {
        Parent = vector<int>(N, -1);
    }
    int root(int A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = root(Parent[A]);
    }

    int size(int A)
    {
        return -Parent[root(A)];
    }
    bool connect(int A, int B)
    {
        A = root(A);
        B = root(B);
        if (A == B)
        {
            return false;
        }
        if (size(A) < size(B))
            swap(A, B);

        Parent[A] += Parent[B];
        Parent[B] = A;

        return true;
    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    vector<int> x(m), y(m);
    UnionFind uf(n);
    rep(i,m){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        uf.connect(p[x[i]], p[y[i]]);
    }
    rep(i,n){
        if(uf.root(i) == uf.root(p[i])){
            ans++;
        }
    }
    cout << ans << endl;
 
}
