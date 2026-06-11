#include <bits/stdc++.h>
using namespace std;
int a, b, q;
vector<long long> s;
vector<long long> t;

bool isOK(vector<long long>& x, int index, long long key) {
    if(x.at(index) >= key) return true;
    else return false;
}

int binary_search(vector<long long>& x, long long key) {
    int ng = -1;
    int ok = (int)x.size()-1;

    while(abs(ok-ng) > 1) {
        int mid = (ok+ng) / 2;
        if(isOK(x, mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin >> a >> b >> q;
    s.push_back(-1e18);
    for(int i = 0; i < a; ++i) {
        long long ins;
        cin >> ins;
        s.push_back(ins);
    }
    s.push_back(1e18);

    t.push_back(-1e18);
    for(int j = 0; j < b; ++j) {
        long long tin;
        cin >> tin;
        t.push_back(tin);
    }
    t.push_back(1e18);

    for(int i = 0; i < q; ++i) {
        long long x;
        cin >> x;
        long long ans = 1e12;
        int cs = binary_search(s, x);
        int ct = binary_search(t, x);

        vector<long long> xs(2,0);
        vector<long long> xt(2,0);
        xs.at(0) = s.at(cs-1);
        xs.at(1) = s.at(cs);
        xt.at(0) = t.at(ct-1);
        xt.at(1) = t.at(ct);

        for(int i = 0; i < 2; ++i) {
            ans = min(ans, abs(xs.at(i)-x)+abs(xt.at(0)-xs.at(i)));
            ans = min(ans, abs(xs.at(i)-x)+abs(xt.at(1)-xs.at(i)));
        }
        for(int i = 0; i < 2; ++i) {
            ans = min(ans, abs(xt.at(i)-x)+abs(xs.at(0)-xt.at(i)));
            ans = min(ans, abs(xt.at(i)-x)+abs(xs.at(1)-xt.at(i)));
        }

        cout << ans << endl;
    }
}