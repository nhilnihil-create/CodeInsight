#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;



int main() {
    int n, k; cin >> n >> k;
    char s;
    int cnt[n+2*k]; int index = 1;
    cnt[0] = 0;
    cin >> s;
    bool isOne = (s == '1');
    bool startOne = (s == '1');
    cnt[1] = 1;
    rep(i, n-1){
        cin >> s;
        if (
            (s == '1' && isOne) || (s == '0' && !isOne)
            ){
            cnt[index] ++;
        }
        else{
            isOne = isOne^true;
            index ++;
            cnt[index] = 1;
        }
    }
    index++;
    rep(i, 2 * k){
        cnt[index+i] = 0;
    }
    // accumulation
    rep(i, index + 2 * k-1){
        cnt[i+1] += cnt[i];
    }
    int ans = 0;
    int ans_y;
    For(i, 1, index){
        if (
            (startOne && i % 2 == 0) || (!startOne && i % 2 == 1)
        ){
            ans_y = cnt[i+2*k-1] - cnt[i-1];
        }
        else{
            ans_y = cnt[i+2*k] - cnt[i-1];
        }
        ans = max(ans, ans_y);
    }
    cout << ans << endl;
    


}

