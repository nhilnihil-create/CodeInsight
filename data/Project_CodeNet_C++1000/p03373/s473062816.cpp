#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int m = min(x, y), M = max(x, y);

    if(a + b <= c*2){
        cout << a*x + b*y << endl;
    }else{
        int ans = 1001001001;
        for(int i = m; i <= M; i++){
            if(x >= y)
            ans = min(ans, c*i*2 + (M-i)*a);
            else
            ans = min(ans, c*i*2 + (M-i)*b);
        }
        cout << ans << endl;
    }
}