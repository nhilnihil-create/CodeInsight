#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    string s; cin >> s;
    int Min = 1000;
    char word;

    vector<int> m(26,0),w(26,0);
    rep(i,s.length()){
        m[(int)(s[i]-'a')] = 1;
    }

    if(s.length() == 26){
        w[(int)(s[s.length()-1]-'a')] = 1;
        for(int i = s.length()-2; i >= 0; i --){
            if(s[i] < s[i+1]){
                rep(j,26){
                    if(w[j] == 1){
                        if(('a' + j) - s[i]> 0 && Min > abs(s[i] - ('a' + j))) {
                            Min = abs(s[i] - ('a' + j));
                            word = (char)('a' + j);
                        }
                    }
                }
                string r = s.substr(0,i);
                cout << r << word;
                return 0;
            }else{
                w[(int)(s[i]-'a')] = 1;
            }

            if(i == 0){
                cout << -1;
                return 0;
            }
        }
    }else{
        rep(i,26){
            if(m[i] == 0){
                cout << s << (char)('a' + i);
                return 0;
            }
        }
    }

    return 0;
}
