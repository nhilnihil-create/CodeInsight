#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n+7] = {0};
    arr[4] = 1, arr[7] = 1;
    for(int i = 4; i <= n; i++){
        if(arr[i] == 1){
            arr[i+4] = 1;
            arr[i+7] = 1;
        }
    }

    if(arr[n] == 1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
