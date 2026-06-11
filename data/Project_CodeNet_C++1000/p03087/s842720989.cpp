
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//"AC"をまとめて扱うのではなく、「Cが隣にあるようなAの個数」を数えると読み替える

int main(){
   int n, q;
   cin >> n >> q;
   string s;
   cin >> s;

    //累積和
   bool leftc=false;
   vector<int> sum(n+1,0);
   rep(i,n){
       if(i+1 < n && s.at(i)=='A' && s.at(i+1)=='C'){
           sum.at(i+1) ++;
       }
       sum.at(i+1) += sum.at(i);
   }

    //クエリ処理
    //今回はACのAの所でsumを+1しているので、
    //A|Cのような分け方があるとうまくいかない
    //そのためrとlを１つ左にずらす。
   rep(i,q){
       int l, r;
       cin >> l >> r;
       r--;l--;
       cout << sum[r] - sum[l] << endl;


   }



}