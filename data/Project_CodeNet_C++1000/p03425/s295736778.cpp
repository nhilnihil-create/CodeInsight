#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;



int main(){
    ll n;
    cin>>n;
    vector<ll> smap(5);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;        
        if('M'==s[0]) smap[0]++;
        if('A'==s[0]) smap[1]++;
        if('R'==s[0]) smap[2]++;
        if('C'==s[0]) smap[3]++;
        if('H'==s[0]) smap[4]++;
    }
    ll ans=0;
    for(int bit=0;bit<(1<<5);bit++){
        vector<int>memo;
        for(int i=0;i<5;i++){
            if(bit&(1<<i)) memo.push_back(i);
        }
        if(3!=memo.size())continue;
        ll res=1;
        for(int i=0;i<memo.size();i++){
            res*=smap[memo[i]];
        }
        ans+=res;
    }
    cout<<ans<<endl;
    return 0;
}