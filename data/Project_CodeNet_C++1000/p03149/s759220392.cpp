#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    string N;
    string S;
    for(int i=0;i<4;i++){
        cin >> N;
        S += N;
    }
    sort(S.begin(),S.end());
    
    if(S == "1479") cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
