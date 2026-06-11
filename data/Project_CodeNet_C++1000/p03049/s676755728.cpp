#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int f[3] = {};

    rep(i,n){
        string s;
        cin >> s;
        int m = s.size();
        if(s[0] == 'B' && s[m-1] == 'A')f[0]++;
        else if(s[0] == 'B')f[1]++;
        else if(s[m-1] == 'A')f[2]++;
        rep(j,m-1){
            if(s[j] == 'A' && s[j+1] == 'B')ans++;
        }
    }

    if(f[0] > 1){
        ans += f[0] - 1;
        f[0] = 1;
    }
    if(f[0] == 1){
        if(f[1] > 0){
            ans++;
            f[1]--;
        }
        if(f[2] > 0){
            ans++;
            f[2]--;
        }
    }
        

    ans += min(f[1], f[2]);

    cout << ans << endl;
    return 0;
}
 
 
