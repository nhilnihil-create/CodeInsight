#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int cnt[4] = {};
    rep(i, 3){
        int a, b;
        cin >> a >> b;
        cnt[a-1]++, cnt[b-1]++;
    }
    rep(i, 4)if(cnt[i]>=3){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}