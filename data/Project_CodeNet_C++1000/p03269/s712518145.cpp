#include <bits/stdc++.h>
using namespace std;

struct edg{
    int u, v, w;
    edg(int u, int v, int w):u(u),v(v),w(w){}
};

vector<int> O;
vector<edg> E;
int L;
int n, m;

int main(){
    cin >> L;
    for(int i = 0; L; i++, L >>= 1){
        if(L & 1){
            O.push_back(i);
        }
    }
    n = O.back() + 1; O.pop_back();
    for(int i = 1; i < n; i++){
        E.emplace_back(i, i+1, 1 << i-1);
        E.emplace_back(i, i+1, 0);
    }
    int w = 1 << n-1;
    while(!O.empty()){
        int z = O.back() + 1; O.pop_back();
        E.emplace_back(z, n, w);
        w += 1 << z-1;
    }
    cout << n << ' ' << E.size() << '\n';
    for(edg &e : E){
        cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    }
}
