#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, A, B; cin >> N >> A >> B;
    vector<int> P(N);
    for (auto& p : P) cin >> p;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < N; i++) {
        if (P[i] <= A) a.push_back(P[i]);
        else if (P[i] <= B) b.push_back(P[i]);
        else c.push_back(P[i]);
    }
    int w = a.size(), e = b.size(), r = c.size();
    int ans = min(min(w, e), r);
    cout << ans << endl;
    return 0;
}