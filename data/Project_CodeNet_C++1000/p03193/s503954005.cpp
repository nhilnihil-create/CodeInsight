#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int N,H,W;
    cin >> N >> H >> W;
    
    int A,B,cnt = 0;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        if(A>=H && B>=W) cnt++;
    }
    
    cout << cnt << endl;
    return 0;
}
