#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define tab " "
#define lli long long int


void read(){
    lli T, D, P, ans;
    cin >> T >> D >> P;

    if(T >= P) ans = P + D;
    else if (T < P){
        if(D >= (P-T)) ans = P + D;
        else if (D < (P-T)) ans = T + D + D + 1;
    }

    cout << ans << endl;

    return;
}

int main(void){
    read();
    return 0;
}