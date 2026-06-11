#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
vector<long long> ll_vec(int n) {
    vector<long long> vec(n);
    for (int i=0; i<vec.size(); i++) cin >> vec.at(i);
    return vec;
}
void PA(vector<long long> vec) {
    for (int i=0; i<vec.size()-1; i++) cout << vec.at(i) << " ";
    cout << vec.at(vec.size()-1) << endl;
    return;
}
map<long long, long long> CL(vector<long long> vec) {
    map<long long, long long> count;
    for (long long x: vec) {
        count[x] += 1;
    }
    return count;
}



int main() {
    using ll = long long;
    using vl = vector<long long>;


    int n; cin >> n;

    vl b=ll_vec(n);

    vl ans(n);
    bool able = false;

    for (int i=0; i<n; i++) {
        ll mx=0;
        able = false;
        for (int j=0; j<b.size(); j++) {
            if (b[j] == j+1) {
                mx = j+1;
                able = true;
            }
        }
        if (able) {
            ans[i] = mx;
            b.erase(b.begin()+mx-1);
        }
        else {
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    if (able) {
        for (ll x:ans) cout << x << endl;
    }
    else {
        cout << -1 << endl;
    }



}
