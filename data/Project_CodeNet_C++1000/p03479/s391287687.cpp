#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll x, y, tmp = 0;
    sc(x) sc(y)
    vector<int> ans;
    tmp = x;
    ans.push_back(x);
    while (tmp * 2 <= y){
        tmp += tmp;
        ans.push_back(tmp);
    }
    cout << ans.size() << endl;
    return 0;
}