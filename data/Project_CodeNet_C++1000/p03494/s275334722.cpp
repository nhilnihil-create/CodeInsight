//2020-08-27, Thu

#include<iostream>
using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while (1) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                a[i] /= 2;
                count++;
            }
        }
        
        if (count == n) {
            ans++;
        } else {
            break;
        }
        
    }
    
    cout << ans << endl;
    
    return 0;
}