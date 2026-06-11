#include <bits/stdc++.h>
using namespace std;
void IA(vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) cin >> vec.at(i);
}
void PA(vector<int> vec) {
    for (int i=0; i<vec.size()-1; i++) cout << vec.at(i) << " ";
    cout << vec.at(vec.size()-1) << endl;
    return;
}

int main() {
    int n; cin >> n;
    vector<long long> l(90);
    l[0] = 2;
    l[1] = 1;
    for (int i=2; i<l.size(); i++) {
        l[i] = l[i-1] + l[i-2];
    }

    long long ans = l[n];
    cout << ans << endl;
}
