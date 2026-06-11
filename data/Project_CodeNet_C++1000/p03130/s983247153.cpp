#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int cnt[4] = {0};
    rep(i, 3){
        int a, b;
        cin >> a >> b;

        cnt[a-1]++;
        cnt[b-1]++;
    }
 
    if(cnt[0] == 1 && cnt[1] == 2 && cnt[2] == 2 && cnt[3] == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}

