#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    string s;
    cin >> s;
    int r = 0, b = 0;
    int ans = 0;
    REP(i,SZ(s)){
        if(s[i]=='0'){
            if(b>0){
                b--;
                ans++;
            }else {
                r++;
            }
        }else{
            if (r > 0)
            {
                r--;
                ans++;
            }
            else
            {
                b++;
            }
        }
    }
    cout << ans*2 << "\n";
    return 0;
}