#include<bits/stdc++.h>
using namespace std;

int a[52];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, max_id = 0, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(abs(a[max_id]) < abs(a[i])) max_id = i;
    }

    if(a[max_id] > 0){
        if(max_id != 0) cnt++;
        for(int i = 1; i < n; i++){
            if(a[i] < 0){
                cnt += 2;
            }
            else cnt++;
        }

        cout << cnt << endl;
        if(max_id != 0) cout << max_id+1 << " " << 1 << endl;
        for(int i = 1; i < n; i++){
            if(a[i] < 0) {
                cout << i << " " << i+1 << endl;
                cout << i << " " << i+1 << endl;
            }
            else cout << i << " " << i+1 << endl;
        }
    }
    else if(a[max_id] == 0) cout << 0 << endl;
    else {
        if(max_id != n) cnt++;
        for(int i = n-2; i >= 0; i--){
            if(a[i] > 0) cnt += 2;
            else cnt++;
        }

        cout << cnt << endl;
        if(max_id != n) cout << max_id+1 << " " << n << endl;
        for(int i = n-2; i >= 0; i--){
            if(a[i] > 0) {
                cout << i+2 << " " << i+1 << endl;
                cout << i+2 << " " << i+1 << endl;
            }
            else cout << i+2 << " " << i+1 << endl;
        }
    }
    return 0;
}