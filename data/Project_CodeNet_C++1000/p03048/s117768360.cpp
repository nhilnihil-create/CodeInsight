#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int R,G,B,N;
    cin  >> R >> G >> B >> N;

    int Rbox = N/R;
    int ans = 0;

    for(int i=0; i<=Rbox; i++){
        for(int j=0; j<=(N-i*R)/G; j++){
            if(((N - i*R - j*G) % B) == 0){
                ans++;
            }
        }
    }
    
    
    cout << ans << endl;
}