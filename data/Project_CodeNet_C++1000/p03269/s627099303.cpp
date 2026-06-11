#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;

int main() {
    int l;
    cin >> l;
    vector<int> v;
    while(l != 1) {
        if(l & 1) v.push_back(1), l--;
        else v.push_back(0), l /= 2;
    }
    int n = 1, m, x = 1;
    typedef array<int, 3> edge;
    vector<edge> e;
    for(int i = v.size() - 1; i >= 0; i--) {
        if(v[i]) {
            e.push_back(edge{1, n, x});
            x++;
        } else {
            for(int i = 0; i < e.size(); i++) {
                e[i][2] *= 2;
            }
            e.push_back(edge{n, n+1, 0});
            e.push_back(edge{n, n+1, 1});
            n++;
            x *= 2;
        }
    }
    cout << n << " " << e.size() << '\n';
    for(auto& ee : e) {
        cout << ee[0] << " " << ee[1] << " " << ee[2] << '\n';
    }
    return 0;
}