#include <bits/stdc++.h>
 
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
    map<int, int> mp;
    rep(i,6){
        int a; cin >> a;
            
        mp[a]++;
    }
    for(auto i : mp){
        if(i.second >= 3){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

}
