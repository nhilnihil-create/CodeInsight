#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
#define INF (1 << 30)
#define INFL (1ll << 60ll);
#define mod 1000000007

int N, ans, mn = INFL;
bool flag;

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        if(b < a){
            mn = min(mn, b);
            flag = true;
        }
        else if(a < b){
            flag = true;
        }
        ans += b;
    }
    if(flag)cout << ans - mn << endl;
    else cout << 0 << endl;

    return 0;
}
