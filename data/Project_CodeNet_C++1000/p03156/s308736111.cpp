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
    int n, a, b;
    cin >> n >> a >> b;
    
    int cnt1, cnt2, cnt3;
    cnt1 = cnt2 = cnt3 = 0;
    rep(i, n){
        int p;
        cin >> p;
        if(p<=a)cnt1++;
        else if(p<=b)cnt2++;
        else cnt3++;
    }
    cout << min(cnt1, min(cnt2, cnt3)) << endl;
}