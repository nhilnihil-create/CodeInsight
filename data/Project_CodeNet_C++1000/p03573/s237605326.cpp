#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans;
    if (a-b == 0){
        ans = c;
    }else if (b-c == 0){
        ans = a;
    }else{
        ans = b;
    }

    cout << ans << endl;
}