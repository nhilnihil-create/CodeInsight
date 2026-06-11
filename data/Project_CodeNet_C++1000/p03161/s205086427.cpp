#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
const long long inf = 1LL << 60;
vector<long long> IL(int n) {
    vector<long long> vec(n);
    for (int i=0; i<vec.size(); i++) cin >> vec.at(i);
    return vec;
}
vector<string> IS(int n) {
    vector<string> vec(n);
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

map<string, long long> CS(vector<string> vec) {
    map<string, long long> count;
    for (string s : vec) {
        count[s] += 1;
    }
    return count;
}


int main() {
    using ll = long long;
    using vl = vector<long long>;


    
    int n, k; cin >> n >> k;

    vl h = IL(n);
    vl dp(n, inf);
    dp[0] = 0;

    for (int i=0; i<n; i++) {
        if (i<k) {
            for (int j=0; j<i; j++) {
                dp[i] = min(dp[i], dp[j]+abs(h[i]-h[j]));
            }
        }
        else {
            for (int j=k; j>0; j--) {
                dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
            }
        }
    }

    cout << dp[n-1] << endl;




}
