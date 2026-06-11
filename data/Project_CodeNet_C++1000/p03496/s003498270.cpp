#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, num, max = 0, id;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        if(abs(max) < abs(num)) max = num, id = i;
    }

    if(max == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << 2*n << endl;
    if(max > 0){
        cout << id << " " << 1 << endl;
        cout << id << " " << 1 << endl;
        for(int i = 2; i <= n; i++){
            cout << i-1 << " " << i << endl;
            cout << i-1 << " " << i << endl;
        }
    }
    else {
        cout << id << " " << n << endl;
        cout << id << " " << n << endl;
        for(int i = n-1; i > 0; i--){
            cout << i+1 << " " << i << endl;
            cout << i+1 << " " << i << endl;
        }
    }
    return 0;
}
