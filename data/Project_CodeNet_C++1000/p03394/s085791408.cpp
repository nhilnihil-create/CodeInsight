#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;

using namespace std;
int n;


void solve(){
    cin >> n;
    if(n == 3){
        cout << 2 << ' ' << 5 << ' ' << 63;
        return;
    }
    if(n == 4){
        cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63;
        return;
    }

    vector<int> a;
    a.clear();
    int s = 0;
    for(int i = 1; i <= 30000; i++) {
        if(i % 2 == 0 || i % 3 == 0){
            a.pb(i);
            s += i;
            if(a.size() == n) {
                break;
            }
        }
    }
    int need = (6 - s % 6) % 6;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] + need <= 30000 && ((a[i] + need) % 2 == 0) || (a[i] + need) % 3 == 0) {
            a[i] += need;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}

int main(){

solve();

return 0;
}
