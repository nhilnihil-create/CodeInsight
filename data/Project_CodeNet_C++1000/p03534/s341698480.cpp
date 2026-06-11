#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    string S;
    cin >> S;
    vector<int> cnt(3);
    for(char c:S)cnt[c == 'a' ? 0 : c == 'b' ? 1 : 2 ]++;
    int N = S.size();
    if(N == 1){
        cout << "YES" << endl;
        return 0;
    }
    //if(cnt[0] > N / 2 || cnt[1] > N / 2 || cnt[2] > N / 2){
    if (cnt[0] > (N + 2) / 3 || cnt[1] > (N + 2) / 3 || cnt[2] > (N + 2) / 3){
        cout << "NO" << endl;
        return 0;
    }


    cout << "YES" << endl;
}