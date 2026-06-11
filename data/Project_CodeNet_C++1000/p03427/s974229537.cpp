#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;

    int ans = 0;
    if(s.size() == 1){
        ans = s[0] - '0';
    }else{
        ans = 9 * (s.size() - 1);
        bool nine = true;
        for (int i = 1; i < s.size(); ++i) {
            if(s[i] != '9'){
                nine = false;
            }
        }

        ans += s[0] - '0';

        if(!nine){
            ans--;
        }
    }

    cout << ans << endl;


    return 0;
}