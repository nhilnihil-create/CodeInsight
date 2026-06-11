#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i < n+1; i += 2){
        int counter = 1;
        for(int j = 1; j < i; j++){
            if (i%j == 0){counter += 1;}
        }
        if (counter == 8){ans += 1;}
    }
    cout << ans << endl;
    return 0;
}