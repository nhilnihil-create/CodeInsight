#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll n, k, t, d;
vector<pair<ll, int>> sushi;

int main() {
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        cin >> t >> d;
        //おいしさを第1要素、ネタを第2要素としてsushiに入れる
        sushi.push_back({d, t});
    }

    //おいしさの昇順にsushiをソート
    sort(sushi.begin(), sushi.end());

    //ネタの種類数を数えるためのmap
    map<int, ll> mp;

    ll ans = 0; //満足ポイント
    ll sum = 0; //おいしさの合計
    ll r = 0; // i < n-k のときに、i番目の寿司とr番目の寿司を入れかえることでネタの種類数を増やす。そのrを調べる変数  

    //おいしさの大きいものから順に調べる
    for(int i = n-1; i >= 0; i--) {
        //おいしさがk番以内に大きい寿司のときは
        if(i >= n-k) {
            //その寿司のネタをキーとするmapの値を1増やして
            mp[sushi[i].second]++;
            //sumにその寿司のおいしさを加える
            sum += sushi[i].first;

            //おいしさがk番目に大きい寿司まで調べたら
            if(i == n-k) {
                //sに現時点でのネタの種類数を入れて
                ll s = mp.size();
                //ansに現時点での満足ポイントを入れる
                ans = sum + s*s;
                // i < n-k のときにi番目の寿司と入れ替える候補をn-k番以降から調べる
                r = n-k;
            }
        }
        //おいしさがk番目より小さい寿司のときは
        else {
            //その寿司のネタがmapのキーになかったら(ネタがすでにキーとしてある場合その寿司はネタの種類数を増やせないので調べなくてよい)
            if(!mp.count(sushi[i].second)) {
                //その寿司のネタをキーとするmapの値を1増やす
                mp[sushi[i].second]++;

                //ネタの種類を２個以上の寿司が持つものの中でおいしさが最も小さい寿司の番号rを求める
                while(r <= n-1 && mp[sushi[r].second] == 1) {
                    r++;
                }
                //そのような寿司が存在しない場合もう調べなくてよいのでループを抜ける
                if(r == n) {
                    break;
                }
                
                //おいしさの合計にi番目の寿司のおいしさを加えて, r番目の寿司のおいしさを引く(つまりr番目の寿司の代わりにi番目の寿司を食べる)
                sum += sushi[i].first - sushi[r].first;
                //r番目の寿司のネタをキーとするmapの値を1減らす
                mp[sushi[r].second]--;
                //r番目の寿司を食べてももうネタの種類は増えないので調べなくてよい。次の入れ替える候補はr+1から調べる
                r++;
                //sに現時点でのネタの種類数を入れて
                ll s = mp.size();
                //ansに現時点での満足ポイントの最大値を入れる
                ans = max(ans, sum + s*s);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}