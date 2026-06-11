#include<bits/stdc++.h>
const int N = 2e5 + 5;
const long long inf = 1e18;
using namespace std;

int n;
long long a[N], ans = inf;

void cal(int x, int y, int z){
    if (0 >= x || x >= y || y >= z || z >= n) return;
    long long B = a[x], C = a[y] - a[x], D = a[z] - a[y], E = a[n] - a[z];
    ans = min(ans, max(max(B, C), max(D, E)) - min(min(B, C), min(D, E)));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    for (int i = 2; i <= n-2; i++){
        int l = 1, r = i, A, B;
        while (l != r){
            int mid = (l + r) >> 1;
            if (a[mid] >= a[i] - a[mid]) r = mid;
            else l = mid+1;
        }
        A = l;
        l = i+1, r = n;
        while (l != r){
            int mid = (l + r) >> 1;
            if (a[mid] - a[i] >= a[n] - a[mid]) r = mid;
            else l = mid+1;
        }
        B = r;
        cal(A, i, B); cal(A-1, i, B); cal(A, i, B-1); cal(A-1, i, B-1);
    }
    cout << ans;
}
