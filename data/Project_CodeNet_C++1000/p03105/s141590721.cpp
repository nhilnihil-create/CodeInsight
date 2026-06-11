#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    //一回a円、b円持ってる、最大c回
    int ans = 0;
    while(ans < c) {
        if(b - a >= 0){
            b -= a;
            ans++;
        }
        else break;
    }

    cout <<  ans << endl;
}