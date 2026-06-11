#include <bits/stdc++.h>
#define fst first
#define snd second
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define repeat_reverse_from_to(i, m, n) for(lint i = (m); (i) >= (lint)(n); --(i))
#define el cout<<endl
#define dump(x) cout<<" "<<#x<<"="<<x
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int s, k; cin >> s >> k;
    vector<string> str(100);
    repeat (i, 100) str[i] = string(100, '.');
    
    bool isreversed = false;
    if (s > k+1) {
        swap(s, k);
        isreversed = true;
    }
    
    auto getpos = [](int n) -> pair<int, int> {
        int a = n / 25;
        int b = n % 25;
        return pair<int, int> {a, b};
    };
    
    repeat (i, k) {
        int a, b;
        tie(a, b) = getpos(i);
        vector<int> dx {0, 1, 2, 0, 1, 2, 0, 1, 2};
        vector<int> dy {0, 0, 0, 1, 1, 1, 2, 2, 2};
        repeat (j, 9) {
            str[a*4+dx[j]][b*4+dy[j]] = '#';
        }
    }
    
    repeat (i, s - 1) {
        int a, b;
        tie(a, b) = getpos(i);
        str[a*4+1][b*4+1] = '.';
    }
    
    if (isreversed) {
        repeat (i, 100) {
            repeat (j, 100) {
                str[i][j] = (str[i][j] == '.' ? '#' : '.');
            }
        }
    }
    
    cout << 100 << " " << 100 << endl;
    repeat (i, 100) cout << str[i] << endl;
    
}