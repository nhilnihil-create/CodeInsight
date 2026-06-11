#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);
int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int d;
        cin >> d;
        mp[d]++;
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int t;
        cin >> t;
        auto itr=mp.find(t);
        if(itr==mp.end() || itr->second<1){
            cout << "NO" << endl;
            return 0;
        }else mp[t]--;
    }
    cout << "YES" << endl;
}