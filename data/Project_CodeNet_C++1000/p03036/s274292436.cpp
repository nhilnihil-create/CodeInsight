#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,d,x_2000;
    cin >> r >> d >> x_2000;
    int ans = x_2000;
    for (int i = 0; i < 10; i++)
    {
        ans = r * ans - d;
        cout << ans << endl;
    }   
}
