#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B, a, b, c, d, e;
    cin >> A >> B;
    int ans = 0;
    for(int i = A; i <= B; i++){
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100 % 10;
        d = i / 1000 % 10;
        e = i / 10000 % 10;
        if(a == e && b == d){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}