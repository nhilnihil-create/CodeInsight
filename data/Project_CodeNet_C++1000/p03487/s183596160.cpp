#include <iostream>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->first - it->second < 0) ans += it->second - it->first;
        else if(it->first - it->second > 0) ans += it->second;
    }
    cout << ans << endl;
    return 0;
}