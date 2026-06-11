#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n-1); i >= 0; i--)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
#define pb push_back
#define all(in) in.begin(),in.end()

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int left = 0, right = n-1;
    vector<char> t(q), d(q); rep(i,q) cin >> t[i] >> d[i];
    rrep(i,q){
        if(s[left] == t[i] && d[i] == 'L') left++;
        else if(left > 0 && s[left-1] == t[i] && d[i] == 'R') left--;
        if(s[right] == t[i] &&  d[i] == 'R') right--;
        else if(right < n-1 && s[right+1] == t[i] && d[i] == 'L') right++;
        if(right <= left){ cout << 0 << endl; return 0; }
    }
    cout << right - left + 1 << endl;
    return 0;
}
