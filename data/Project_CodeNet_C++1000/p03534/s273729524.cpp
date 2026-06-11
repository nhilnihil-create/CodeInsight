#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    string S;
    cin >> S;
    int cnt[3] = {}, l = (S.size() + 2) / 3;
    for(auto c:S)cnt[c-'a']++;
    if(cnt[0] <= l && cnt[1] <= l && cnt[2] <= l)cout << "YES" << endl;
    else cout << "NO" << endl;
}