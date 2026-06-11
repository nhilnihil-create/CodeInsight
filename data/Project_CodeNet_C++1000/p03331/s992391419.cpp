#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int ans = 100000;
    for (int i = 1; i <= N - 1; i++){
        int A = i;
        int B = N - i;
        int sub_ans = 0;
        sub_ans += A % 10;
        if (A >= 10) sub_ans += (A / 10) % 10;
        if (A >= 100) sub_ans += (A / 100) % 10;
        if (A >= 1000) sub_ans += (A / 1000) % 10;
        if (A >= 10000) sub_ans += (A / 10000) % 10;
        sub_ans += B % 10;
        if (B >= 10) sub_ans += (B / 10) % 10;
        if (B >= 100) sub_ans += (B / 100) % 10;
        if (B >= 1000) sub_ans += (B / 1000) % 10;
        if (B >= 10000) sub_ans += (B / 10000) % 10;
        ans = min(ans,sub_ans);
    }
    cout << ans << endl;
}
