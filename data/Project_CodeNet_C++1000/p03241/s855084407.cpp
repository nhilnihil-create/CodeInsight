//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int n, m;
    cin >> n >> m;

    vi g;
    for(int i =1; i <= m; ++i) {
        if(m%i == 0) {
            g.push_back(i);
        }
        if((i+1)*(i+1) > m) break;
    }
    for(int i = g.size()-1; i >= 0; --i) {
        if(i*i == m) continue;
        g.push_back(m/g[i]);
    }

    int j=0;
    while(1) {
        if(j+1 == g.size()) {
            cout << g[j] << endl;
            break;
        }
        if(g[j+1] > m/n) {
            cout << g[j] << endl;
            break;
        }


        ++j;
    }
}