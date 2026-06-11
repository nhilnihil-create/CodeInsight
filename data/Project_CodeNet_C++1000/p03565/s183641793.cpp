#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

// 最大文字数　注意
const int MAX_S = 55;

int main(){
    string ss, tt;
    cin >> ss;
    cin >> tt;
    int n = ss.length(), m = tt.length();
    vector<char> s(n);
    vector<char> t(m);
    rep(i, n) s.at(i) = (char)ss.at(i);
    rep(i, m) t.at(i) = (char)tt.at(i);

    int last = -1;
    for(int i = n-1; i >= 0; i--){
        bool tmp = true;
        for(int j = i; j > i - m; j--){
            if(j < 0 || (s.at(j) != '?' && s.at(j) != t.at(m-i+j-1))){
                tmp = false;
                break;
            }
        }
        if(tmp == true) {
            last = i;
            break;
        }
    }
    if(last == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    int first = last - m + 1;
    for(int i = 0; i < n; i++){
        if(i == first){
            for(i; i <= last; i++){
                cout << t.at(i-first);
            }
            i--;
        }
        else if(s.at(i) == '?') cout << 'a';
        else cout << s.at(i);
    }
    cout << endl;
}