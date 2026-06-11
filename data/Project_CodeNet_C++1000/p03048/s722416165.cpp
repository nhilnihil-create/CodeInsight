#include <bits/stdc++.h>
using namespace std;

int main(){

    int R,G,B,N;
    cin >> R >> G >> B >> N;

    int r=0,g=0;
    long long int ans=0;
    while(1){
        while(1){
            if(N-r*R-g*G<0) break;
            if((N-r*R-g*G)%B==0) ans++;
            g++;
        }
        if(g==0) break;
        g=0;
        r++;
    }

    cout << ans << endl;
}