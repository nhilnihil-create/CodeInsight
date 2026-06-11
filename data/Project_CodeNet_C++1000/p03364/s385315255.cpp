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
    cin >> n;
    string s[n];
    rep(i, n)cin >> s[i];
    int cnt = 0;
    rep(a, n){
        bool flag = true;
        rep(i, n)rep(j, n){
            if(s[i][(j+a)%n]!=s[j][(i+a)%n]){
                flag = false;
            }
        }
        if(flag)cnt++;
    }
    cout << cnt*n << endl;
}