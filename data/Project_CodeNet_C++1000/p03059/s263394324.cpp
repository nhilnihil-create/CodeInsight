#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b ,t;
    cin >> a >> b >> t;
    int time = 0;
    int ans = 0;
    while(time <= t){
        if(time == 0 ){
            time = a;
            continue;
        }
        ans += b;
        time += a;
    }

    cout << ans << endl;
}