#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    map<int,int> mp;

    int n;  cin >> n;
    rep(i,n){
        int x;  cin >> x;
        mp[x]++;
    }

    cout << mp.size() << endl;

    return 0;
}