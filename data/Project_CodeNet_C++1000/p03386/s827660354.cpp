#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> v;

    for(int i=A; i<A+K; i++) {
        if(i > B) break;
        v.push_back(i);
    }
    for(int i=B; i>B-K; i--) {
        if(i < A) break;
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i=0; i < v.size(); i++) cout << v[i] << endl;
}
