#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)

typedef pair<int, int> pint;
#define INF 1e9

struct w_union_find{
    // d_ws[a]はroot -> aの重み.
    vector<int> d_ws;
    vector<int> ps;
    w_union_find(int n = 1) : ps(n, -1), d_ws(n, 0){}

    int root(int a){
        if(ps[a] < 0){
            return a;
        }
        int r = root(ps[a]);
        d_ws[a] += d_ws[ps[a]];
        return ps[a] = r;
    }

    bool same(int a, int b){
        return root(a) == root(b);
    }

    int weight(int a){
        root(a);
        return d_ws[a];
    }

    int diff_weight(int a, int b){
        return weight(b) - weight(a);
    }

    bool unite(int a, int b, int w){
        if(same(a, b)){
            return diff_weight(a, b) == w;
        }

        w -= weight(b);
        w += weight(a);

        a = root(a);
        b = root(b);

        if(ps[a] > ps[b]){
            swap(a, b);
            w *= -1;
        }
        ps[a] += ps[b];
        ps[b] = a;
        d_ws[b] = w;

        return true;
    }

};

int main(){
    int N, M;
    cin >> N >> M;
    w_union_find uf(N);

    rep(i, M){
        int l, r, d;
        cin >> l >> r >> d;
        if(! uf.unite(l, r, d)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
