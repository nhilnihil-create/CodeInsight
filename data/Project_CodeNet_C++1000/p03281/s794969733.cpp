#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i += 2){
        int yks = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0) yks++;
        }
        if(yks == 8) ans++;
    }
    cout << ans << endl;
}