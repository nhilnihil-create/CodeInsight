#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,t, aa=0, ans =0;
    cin >> a >> b >> t;
    aa = a;
    while(aa < t+0.5){
        aa += a;
        ans += b;
    }
    cout << ans << "\n";
}
