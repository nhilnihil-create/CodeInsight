#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
int main(){
    int n, k; sc(n), sc(k);
    string s; cin >> s;
    bool check = false;
    int ans = 0, cnt = 0, left = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            if (!check) cnt += 1;
            while (cnt > k){
                left++;
                if (s[left]=='1' && s[left-1]=='0') cnt--;
            }
            check = true;
        }else check = false;
        ans = max(ans, i-left+1);
    }
    cout << ans << endl;
    return 0;
}