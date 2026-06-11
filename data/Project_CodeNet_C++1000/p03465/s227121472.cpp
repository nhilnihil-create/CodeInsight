#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    bitset<2000*2000 + 1> dp;
    dp[0] = 1;
    for(int i=0; i<n; i++){
        dp |= (dp << a[i]);
    }

    int x = (sum + 1) / 2;
    while(1){
        if(dp[x] == 1){
            cout << x << endl;
            return 0;
        }
        x += 1;
    }
    return 0;
}