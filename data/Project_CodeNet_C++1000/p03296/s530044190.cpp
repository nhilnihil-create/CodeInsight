#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int N;
    cin >> N;
    int a[111];
    map<int,int> mp;
    for(int i=0;i<N;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    
    int change = 0;
    for(int i=0;i<N;i++){
        if(mp[a[i]]==0){
            change = a[i];
            break;
        }
    }
    
    int cnt = 0;
    for(int i=1;i<N;i++){
        if(a[i-1]==a[i]){
            a[i] = change;
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}
