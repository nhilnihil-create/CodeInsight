#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;cin >> n;
    int ans = 0;

    for(int i=1;i<=n;i++){
        if(i%2 == 0)continue;
        int sum = 0;
        for(int j=1;j<=i;j++) if(i%j == 0) sum++;
        if(sum == 8) ans++;
    }

    cout << ans << endl;
}
