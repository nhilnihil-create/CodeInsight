#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<58;

int main(){
    int a, b, q;
    cin >> a >> b >> q;
    
    vector<long long> s(a+2);
    vector<long long> t(b+2);
    
    /*
    それぞれ配列外アクセスになる可能性があるため
    番兵を用意しておく
    */
    s[0] = -INF;
    s[a+1] = INF;
    
    t[0] = -INF;
    t[b+1] = INF;
    
    for (int i = 1; i <= a; i++) cin >> s[i];
    for (int i = 1; i <= b; i++) cin >> t[i];

    for (int i = 0; i < q; i++){
        long long ans = INF;
        long long x;
        cin >> x;
        
        //　最寄り神社の右端のindexを求める
        int rightJinja = lower_bound(s.begin(),s.end(),x) - s.begin();
        
        // 最寄り神社の左端のindexを求める
        int leftJinja = rightJinja-1;
        
        // 最寄り寺の右端のindexを求める
        int rightTera = lower_bound(t.begin(),t.end(),x) - t.begin();
        
         // 最寄り寺の左端のindexを求める
        int leftTera = rightTera-1;
        
        
        // 最寄りの神社, 寺の訪れ方を全探索する 8通りある
        for (int j = leftJinja; j <= rightJinja; j++){
            for (int k = leftTera; k <= rightTera; k++){
                long long dist1 = abs(s[j] - x) + abs(s[j]-t[k]);
                long long dist2 = abs(t[k]-x) + abs(t[k]-s[j]);
                
                ans = min(ans,dist1);
                ans = min(ans, dist2);
            }
        }
        cout << ans << endl;
    }
}
