#include <bits/stdc++.h>
using namespace std;
int n, a[100005];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int v = a[n-1], vi = 0;
    for(int i = 0; i < n-1; i++){
        int w = (2 * a[i] > a[n-1] ? a[i] - (a[n-1]+1)/2 : a[n-1]/2-a[i]);
        if(v > w){
            v = w;
            vi = i;
        }
    }
    cout << a[n-1] << ' ' << a[vi] << '\n';
}