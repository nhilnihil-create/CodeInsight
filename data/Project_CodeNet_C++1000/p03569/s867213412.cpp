//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int i,j;
    i = 0;
    j = n-1;
    int ans = 0;
    while(j > i){
        int coui = 0, couj = 0;
        while(s[i] == 'x') {
            i++;
            coui++;
        }
        while(s[j] == 'x') {
            j--;
            couj++;
        }
        ans += abs(coui-couj);
        if(s[i] != s[j]) {
            cout << -1 << endl;
            return 0;
        }
        i++;
        j--;
    }

    cout << ans << endl;
}