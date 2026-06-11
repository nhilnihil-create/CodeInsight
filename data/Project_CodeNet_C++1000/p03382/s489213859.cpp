#include <bits/stdc++.h>

using namespace std;
int n, a[100001];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int mid = ((a[n] + 1) / 2), pos = 0;
    for(int i = 1; i < n; i++){
        if(abs(pos - mid) > abs(a[i] - mid)){
            pos = a[i];
        }
    }
    cout << a[n] << " " << pos;
}
