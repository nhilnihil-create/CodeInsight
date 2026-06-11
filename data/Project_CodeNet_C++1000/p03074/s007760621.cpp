#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
template<class T> void chmax(T& a, T b) { if(a < b) a = b; }

vector<pair<char, int>> runlength(string s) {
    int n = s.size();
    vector<pair<char, int> > res;
    char pre = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(pre != s[i]){
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    res.push_back({pre, cnt});
    return res;
}

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    auto run = runlength(s);

    int m = run.size();
    int ans = 0, sum = 0, l = 0, z = 0;
    for(int r = 0; r < m; r++){
        sum += run[r].second;
        if(run[r].first == '0') z++;
        while(k < z){
            sum -= run[l].second;
            if(run[l].first == '0') z--;
            l++;
        }
        chmax(ans, sum);
    }
    cout << ans << endl;

}
