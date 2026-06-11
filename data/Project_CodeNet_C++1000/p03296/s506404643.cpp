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
    int n;cin >> n;
    int pre = 0, count = 0;
    int ans=0;
    //vector
    //REP()
    REP(i,n){
        int c;
        cin >> c;
        //cout << c << "\n";
        if(i==0){
            pre = c;
        }
        if(pre==c){
            count += 1;
        }else{
            ans += (count / 2);
            count = 1;
        }
        pre = c;
    }
    ans += (count / 2);

    cout << ans <<"\n";

    return 0;
}