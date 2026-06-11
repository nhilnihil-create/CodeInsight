 #include<bits/stdc++.h>
 
 using namespace std;
 typedef long long ll;
 #define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
 
 int main() {
 
     int n,m; cin >> n >> m;
     vector<int> a(m);
     rep(i, m) {
         cin >> a[i];
     }
     // 入力例的にa[i]の順は大小が考慮されていないので、降順ソートしておく
     sort(a.begin(), a.end(), greater<int>() );
 
     // 数値ごとのマッチ利用本数
     vector<int> match_num{2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};

     vector<int> dp(11000, -INT_MAX);
     for(int i=1; i <= n; i++) {
         int tmp = -INT_MAX;
         rep(j, m) {
             if(i-match_num[a[j]-1] < 0) continue;
             if(i-match_num[a[j]-1] == 0) {
                 tmp = 1;
             } else if(dp[i-match_num[a[j]-1]] > 0) {
                 tmp = max(tmp, dp[i-match_num[a[j]-1]]+1);
             }
         }
         dp[i] = tmp;
     }
     
 
     // 結果を求める
     string ans = "";
     int remain = dp[n]; // 期待される桁数
     int match = n; // 残りのマッチ本数
     dp[0] = 0; // 計算用の対策, dp[0]の時を0にしておく(最後の１桁を求める時の判定用)
 
     while(match > 0) {
         rep(i, m) {
             if(remain-1 == dp[match-match_num[a[i]-1]] && match-match_num[a[i]-1] >= 0) {
                 match -= match_num[a[i]-1];
                 remain -= 1;
                 ans += to_string(a[i]);
                 break;
             }
         }
     }
 
     cout << ans << endl;
     return 0;
 }