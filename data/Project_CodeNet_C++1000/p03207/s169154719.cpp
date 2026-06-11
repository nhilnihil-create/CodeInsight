#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(_) cerr << #_ << ": " << (_) << '\n'
#define _GLIBCXX_DEBUG
#else
#define debug(_) 0
#endif // LOCAL

int main(){
    int N;
    vector<int> ps;

    cin >> N;
    ps.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ps[i];
    }

    cout << (accumulate(ps.begin(), ps.end(), 0) - *max_element(ps.begin(), ps.end()) / 2) << '\n';
    
    return 0;
}