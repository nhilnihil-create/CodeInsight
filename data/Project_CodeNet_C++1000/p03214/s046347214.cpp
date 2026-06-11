#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N;    
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }



    double ave = accumulate(begin(a), end(a), 0.0) / a.size();
    double min_diff = 1e9;
    // vector<double> diff;
    vector<int> diff;
    for(int i = 0; i < N; i++){
        // double tmp_diff = abs(N*a[i] - N*ave);
        int tmp_diff = abs(N * a[i] -  N *ave);
        diff.push_back(tmp_diff);
    }

    auto minitr = min_element(begin(diff), end(diff));
    size_t idx = distance(begin(diff), minitr);
    cout << idx << endl;

    return 0;
}