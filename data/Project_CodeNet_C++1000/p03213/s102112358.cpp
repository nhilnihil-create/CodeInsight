#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 2; i <= n; ++i){
        int m = i;
        for(int x = 2; x*x <= i;++x){
            while(m%x == 0) {
                m /= x;
                mp[x]++;
            }
        }
        if(m != 1) mp[m]++;
    }
    int ans = 0;
    int n3 = 0,n5 = 0,n25 = 0,n75 = 0,n15 = 0;
    for(auto x : mp){
        if(x.second >= 74) n75++;
        if(x.second >= 2) n3++;
        if(x.second >= 4) n5++;
        if(x.second >= 24) n25++;
        if(x.second >= 14) n15++;
    }
    cout << n75+n15*(n5-1)+n25*(n3-1)+n5*(n5-1)/2*(n3-2) << endl;
}