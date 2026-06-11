#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;


signed main(){
    int A;
    map<int,int> mp;
    for(int i=0;i<6;i++){
        cin >> A;
        mp[A]++;
    }
    int cnt = 0;
    
    for(int i=1;i<=4;i++){
        if(mp[i]!=2) cnt++;
    }
    
    if(cnt==2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
