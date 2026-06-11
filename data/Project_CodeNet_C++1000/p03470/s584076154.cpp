#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n;
    int ans=0;
    cin >> n;
    map<int,int>mochi;
    rep(i,n){
        int a;
        cin >> a;
        mochi[a]++;
    }
    for(auto c:mochi){
        ans++;
    }
    cout << ans << endl;
    
}