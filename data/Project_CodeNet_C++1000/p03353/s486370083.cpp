#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();

    vector<string> v;
    for(int i=1; i<=min(n,5); i++){
        for(int j=0; j<n-i+1; j++){
            v.push_back(s.substr(j, i));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.at(k-1) << endl;
    return 0;
}
