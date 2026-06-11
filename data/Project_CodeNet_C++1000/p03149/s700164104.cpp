#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    bool cnt[10] = {false};
    int n;
    rep(i, 4){
        cin >> n;
        cnt[n] = true;
    }

    if(cnt[1] && cnt[9] && cnt[7] && cnt[4]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
