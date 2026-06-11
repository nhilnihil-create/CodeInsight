#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void){

    int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
    int max_ABmaisu=max(2*X,2*Y);
    int max_Amai=X, max_Bmai=Y;
    int ans=1e+9;

    for (int ABmai = 0; ABmai <= max_ABmaisu; ++ABmai) {
        int Amai = ABmai/2 >= X ? 0 : X - ABmai/2;
        int Bmai = ABmai/2 >= Y ? 0 : Y - ABmai/2;
        int Akane = Amai*A, Bkane = Bmai*B, ABkane = ABmai*C;
        ans = min(ans, Akane+Bkane+ABkane);
    }

    cout<<ans<<endl;
    return 0;
}