#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s;
    cin >> s;
    vector<int> alp(26, 0);
    rep(i, s.size()) alp[s[i]-'a']++;
    if (s.size() == 26){
        for(int i = 25; i >= 0; i--){
            char sEnd = s[i] - 'a';
            alp[sEnd]--;
            s.pop_back();
            for(int j = sEnd+1; j < 26; j++){
                if(alp[j] == 0){
                    s += 'a' + j;
                    cout << s << endl;
                    return 0;
                }
            }
        }
        cout << -1 << endl;
        return 0;
    }else{
        rep(i,26){
            if (alp[i] == 0){
                s += 'a' + i;
                cout << s << endl;
                return 0;
            }
        }
    }


}