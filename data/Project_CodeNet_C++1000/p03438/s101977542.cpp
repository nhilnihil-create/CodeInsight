#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<ll> A(N), B(N);

  ll a_sum = 0;
  ll b_sum = 0;

  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    a_sum += A.at(i);
  } 
  for(int i = 0; i < N; i++){
    cin >> B.at(i);
    b_sum += B.at(i);
  } 
  string ans;
  ll change_time = b_sum - a_sum;
  // 変更していい回数
  cerr << "change_time: " << change_time << endl;


  if(change_time < 0){
    ans = "No";
  } else { 
    ll b_stock = 0; // Bに+1していい回数
    
    for(int i = 0; i < N; i++){
      ll tmp = B[i] - A[i];

      if(tmp >= 0){
        // A[i]をB[i]以上になる様に最小限変更する
        ll change_num = (tmp+1)/2;
        change_time -= change_num;
        a_sum += 2 * change_num;

        // 差が奇数なら、B[i]++しておく その分、自由なb_stockは減る
        if(tmp%2 == 0){
          b_stock += change_num;
        } else {
          b_stock += change_num - 1;
          b_sum += 1;
        }
      }
    }
    cerr << "change_time: " << change_time << endl;

    if(change_time < 0){
      ans = "No";
    } else if(change_time > 0){
      // 余ったら適当に足しておく
      a_sum += 2 * change_time;
      b_stock += change_time;
    }

    // 差を埋められるかどうか
    if(a_sum - b_sum == b_stock){
      ans = "Yes";
    } else { 
      ans = "No";
    }
  }

  cout << ans << endl;
}
