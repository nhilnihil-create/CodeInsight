#include <bits/stdc++.h>
using namespace std;

int main(void){
    int x, ans=1;
    cin >> x;
    for (int b=1; b<=(int)sqrt(x); b++){
        for (int p=2; p<=1000; p++){
            if (pow(b, p) > x){
                ans = max(ans, (int)pow(b, p-1));
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}