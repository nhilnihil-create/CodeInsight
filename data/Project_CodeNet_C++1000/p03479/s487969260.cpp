#include<bits/stdc++.h>

using namespace std;

int main(){
    long long X,Y;
    int ans;

    cin >> X >> Y;

    for(ans = 1;X * 2 <= Y;ans++,X *= 2);

    cout << ans << endl;
}