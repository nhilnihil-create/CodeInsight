#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(int i = 0; i < n; i++){
        map<char, int> mpx, mpy;
        for(int j = 0; j <= i; j++){
            // X
            mpx[s[j]]++;
        }
        for(int j = i + 1; j < n; j++){
            // Y
            mpy[s[j]]++;
        }

        int tmp_ans = 0;
        for(int k = 0; k < 26; k++){
            if(mpx[char('a'+k)] >= 1 && mpy[char('a'+k)] >= 1){
                tmp_ans++;
            }
        }
        ans = max(ans, tmp_ans);
    }
    cout << ans << endl;
    return 0;
}