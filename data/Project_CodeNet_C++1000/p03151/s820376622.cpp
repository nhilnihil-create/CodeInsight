#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int cnt=0;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll husoku=0;
    vector<int> huriwake;

    rep(i,n){
        ll c = a[i] - b[i];
        if(c < 0){
            husoku += -c;
            cnt++;
        }
        else if(c>0){
            huriwake.push_back(c);
           // cout << c << endl;
        }
    }
    sort(huriwake.rbegin(),huriwake.rend());
    
    //cout << husoku <<endl;
    rep(i,huriwake.size()){
        if(husoku> 0){
            husoku -= huriwake[i];
            cnt++;
        }
    }
    // cout << husoku  <<endl;
    if(husoku <= 0)cout << cnt << endl;
    else cout << -1 <<endl;
    return 0;
    
    
    

}