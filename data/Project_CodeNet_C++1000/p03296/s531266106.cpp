#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

const int maxn = 105;
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int len = 0;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != a[i - 1]){
            ans += len / 2;
            len = 1;
        }else{
            len++;
        }
    }
    ans += len / 2;
    cout << ans << endl;
    return 0;
}
