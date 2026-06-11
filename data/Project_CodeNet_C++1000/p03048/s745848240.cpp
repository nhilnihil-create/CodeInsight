#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans =0;
    for(int r=0; r<=(N/R); r++){
        for(int g=0; g<=((N-r*R)/G); g++){
            int count = r*R + g*G;
            if((N-count)%B != 0){continue;}
            int b = (N-count)/B;
            if( b >= 0){
                ans += 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}