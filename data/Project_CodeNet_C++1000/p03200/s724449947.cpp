#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;

    long long b_count = 0;
    long long ans = 0;
    rep(i,(int)S.size()){
        char c = S[i];
        if( c == 'B'){
            b_count += 1;
        }else{
            ans += b_count;
        }
    }
    cout << ans << endl;
    return 0;
    
}