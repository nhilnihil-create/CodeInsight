#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
map<char, int> m;
signed main() {
    int n;
    cin >> n;
    string node;
    cout << n-1 << endl;
    cin >> node;
    if(node=="Vacant") {
        return 0;
    }
    cout << 0 << endl;
    cin >> node;
    if(node=="Vacant") {
        return 0;
    }

    int left = 0;
    int right = n-1;
    int mid = (left+right)/2;
    while(left<=right) {
        cout << mid << endl;
        string now;
        cin >> now;
        if(now=="Vacant") {
            return 0;
        }
        if((mid%2==0 && now==node) || (mid%2==1 && now!=node)) {
            left = mid+1;
            mid = (left+right)/2;
        }else {
            right = mid-1;
            mid = (left+right)/2;
        }
    } 
  return 0;
}

