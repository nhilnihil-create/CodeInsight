#include <bits/stdc++.h>

using namespace std;

#define ll long long int 
#define F first
#define S second
#define pb push_back

const ll N = 1e5 + 10;
const ll M = 1e6 + 10;
const ll MOD =  1e9 + 7;
const ll INF = 1e9 + 10;
const ll INFtar = 1e18;
int n, a[N], b[N], dif[N], ans;
ll suma, sumb;
bool mrk[N];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        suma += (ll)a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        sumb += (ll)b[i];
        dif[i] = a[i] - b[i];
    }
    if (suma < sumb) return cout << "-1\n", 0;
    sort(dif, dif + n);
    int pntl = 0, pntr = n - 1;
    while (dif[pntl] < 0){
        ans ++;
        while (dif[pntl] < 0){
            if (dif[pntr] <= (-dif[pntl])){
                dif[pntl] += dif[pntr];
                dif[pntr] = 0;
                ans += (!mrk[pntr]);
                mrk[pntr] = 1;
                pntr--;
            }
            else if ((-dif[pntl]) < dif[pntr]){
                dif[pntr] += dif[pntl];
                dif[pntl] = 0;
                ans += (!mrk[pntr]);
                mrk[pntr] = 1;
            }
        }
        pntl ++;
    }
    cout << ans << '\n';
    return 0;
}