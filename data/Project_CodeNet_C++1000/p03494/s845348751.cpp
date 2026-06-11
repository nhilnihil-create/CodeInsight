#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans = 0;
    cin >> n;
    int array[n];
    for(int i=0; i<n; i++) cin >> array[i];

    while(true){
        bool breaker = false;
        for(int i=0; i<n; i++){
            if(array[i]%2 == 1) breaker = true;
        }
        if(breaker == true) break;

        
        for(int i=0;  i<n; i++) array[i] /= 2;
        ans++;

    }
    cout << ans << endl;
}