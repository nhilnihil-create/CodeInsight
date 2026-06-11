#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    map<int,int>mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    
    string ans = "NO";
    
    if(mp[1]>0
    &&mp[9]>0
    &&mp[7]>0
    &&mp[4]>0)ans ="YES";
    cout << ans <<endl;
}
