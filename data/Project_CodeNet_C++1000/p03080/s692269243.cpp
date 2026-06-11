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
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    rep(i, n)if(s[i]=='R')cnt++;
    if(cnt > n/2)cout << "Yes";
    else cout << "No";
}