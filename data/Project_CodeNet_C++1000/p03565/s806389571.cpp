#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<string>v;
    int count = 0;
    rep(i, 0, max(0, n-m+1)){
        string temp = s;
        bool a = true;
        rep(j, 0, m){
            if(i+j+1>n) break;
            if(temp[i+j] == '?' || temp[i+j] == t[j]){
                temp[i+j] = t[j];
            }else break;

            if(j == m-1){
                rep(k, 0, n){
                    if(temp[k] == '?')temp[k]='a';
                }
                v.push_back(temp);
            }
        }
    }
    if(v.size() == 0){
        cout << "UNRESTORABLE" <<endl;
        return 0;
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    return 0;
}