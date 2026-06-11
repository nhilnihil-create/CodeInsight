/*
      author  : nishi5451
      created : 14.08.2020 22:23:05
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,t,a;
    cin >> n >> t >> a;
    map<double,int> mp;
    rep(i,n){
        int h;
        cin >> h;
        double key = fabs(a-(t-h*0.006));
        mp[key]=i;
    }
    auto itr = mp.begin();
    cout << int(itr->second)+1 << endl;
    return 0;
}