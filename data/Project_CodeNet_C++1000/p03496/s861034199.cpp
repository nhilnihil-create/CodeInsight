#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, int>> b(n);// (a[i], i)
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = make_pair(a[i],i);// 0-indexed (be careful)
    }
    sort(b.begin(),b.end());

    vector<pair<int, int>> ans;

    // mise en place
    if(b[0].first < 0 && b[n-1].first > 0){// make it "all non-negative" or "all non-positive"
        if(abs(b[n-1].first) >= abs(b[0].first)){
            for(int i=0; i<n; i++){
                a[i] += b[n-1].first;
                ans.push_back({b[n-1].second+1, i+1});
            }
        }
        if(abs(b[n-1].first) <  abs(b[0].first)){
            for(int i=0; i<n; i++){
                a[i] += b[0].first;
                ans.push_back({b[0].second+1, i+1});
            }
        }
    }

    sort(a.begin(),a.end());

    // case(1) all non-negative
    if(a[0] >= 0){
        for(int i=1; i<n; i++){
            ans.push_back({i, i+1});// a[i] += a[i-1];
        }
    }
    // case(2) all non-positive
    if(a[0] < 0){
        for(int i=n-2; i>=0; i--){
            ans.push_back({i+2, i+1});//a[i] += a[i+1];
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x.first << " " 
             << x.second << endl;
    }
    return 0;
}