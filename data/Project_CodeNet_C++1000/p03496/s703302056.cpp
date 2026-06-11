#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    vector<int> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int x, int y){
        return a[x] < a[y];
    });
    int cnt;
    vector<pair<int, int>> ans;
    if(a[ord.front()] < 0 && a[ord.back()] > 0){
        int pos;
        if(abs(a[ord.front()]) >= a[ord.back()])pos=ord.front();
        else pos = ord.back();
        rep(i, n){
            a[i] += a[pos];
            cnt++;
            ans.push_back(make_pair(pos+1, i+1));
        }
    }
    if(a[ord.front()] >= 0){
        for(int i = 1; i < n; ++i){
            if(a[i] < a[i-1]){
                a[i]+=a[i-1];
                cnt++;
                ans.push_back(make_pair(i, i+1));
            }
        }
    }
    else{
        for(int i = n-2; i >= 0; --i){
            if(a[i] > a[i+1]){
                a[i]+=a[i+1];
                cnt++;
                ans.push_back(make_pair(i+2, i+1));
            }
        }
    }
    
    cout << cnt << endl;
    rep(i, cnt)cout << ans[i].first << " " << ans[i].second << endl;

}