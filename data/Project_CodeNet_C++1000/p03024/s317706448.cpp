#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int cnt = 0;
    string S;
    cin >> S;
    for(auto c:S)if(c == 'o')cnt++;
    int rem = 15 - S.size();
    cnt += rem;
    if(cnt >= 8)cout << "YES" << endl;
    else cout << "NO" << endl;
}