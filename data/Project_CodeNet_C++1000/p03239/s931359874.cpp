#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int n, T;
    cin >> n >> T;
    int res = 1001;
    rep0(i,n){
        int c, t;
        cin >> c >> t;
        if(T>=t&&res>c){
            res=c;
        }
    }
    if(res== 1001){
        cout << "TLE" << endl;
    }else{
    cout << res << endl;
    }
}
