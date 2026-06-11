#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

int cur = 0;
string S, ans = "KIHBR";
bool flag;
vi id;

void solve(){

    rep(i, S.size()){
        if(ans[cur] == S[i]) {
            id.push_back(i);
            cur++;
        } else {
            if(S[i] != 'A') break;
        }
    }

    // rep(i, id.size()){
    //     cout << id[i] << endl;
    // }

    if(cur != 5) flag = false;
    else {
        if(id[0] < 2 && id[1] - id[0] == 1 && id[2] - id[1] == 1 && id[3] - id[2] <= 2 && id[4] - id[3] <= 2 && S.size() - id[4] <= 2)
            flag = true;
        else
            flag = false;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    cin >> S;

    solve();
}
