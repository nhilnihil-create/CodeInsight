#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll  X,Y;
    cin >> X >> Y;
    ll A=X;
    int ans=0;
    while (A<=Y){
        A=A*2;
        ans+=1;
    }
    cout << ans << endl;
    return 0;
}