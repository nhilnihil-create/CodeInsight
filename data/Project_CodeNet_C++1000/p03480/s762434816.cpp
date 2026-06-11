#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include<queue>

using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n; ++i)
#define ALL(a) (a).begin(),(a).end()
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)

int main(){
    string s;
    cin >> s;

    ll len = s.size();
    ll res = len;
    for(ll i = 1; i < len; ++i){
        if(s[i-1] == s[i])continue;
        if(i > len-i)res = min(i, res);
        else res = min(len-i, res);
    }
    cout << res << endl;
}