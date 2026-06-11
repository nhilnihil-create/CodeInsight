#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
    public:
        vector<int> Parent;

        UnionFind(int N) {
            Parent = vector<int>(N, -1);
        }

        int getRoot(int X) {
            if(Parent[X] < 0) return X;
            else return Parent[X] = getRoot(Parent[X]);
        }

        int getSize(int X) {
            return -Parent[getRoot(X)];
        }

        bool merge(int X, int Y) {
            X = getRoot(X);
            Y = getRoot(Y);
            if(X == Y) return false;
            if(getSize(X) < getSize(Y)) swap(X, Y);

            Parent[X] += Parent[Y];
            Parent[Y] = X;

            return true;
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    UnionFind uni(n);
    vector<int> a(m), b(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    vector<long long> ans(m);
    ans[m-1] = (long long) n*(n-1)/2;
    for(int i = m-1; i >=1; --i){
        ans[i-1] = ans[i];
        if(uni.getRoot(a[i]) != uni.getRoot(b[i])){
            ans[i-1] -= (long long) uni.getSize(a[i])*uni.getSize(b[i]);
            uni.merge(a[i], b[i]);
        }
    }
    
    for(int i = 0; i < m; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}
//Saw the solution video
//写経