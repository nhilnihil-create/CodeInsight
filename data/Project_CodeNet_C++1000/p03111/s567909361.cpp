#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; cout << "i=  ";for(ll i=0; i<num; i++) cout << i << "   ";cout << endl;  
  cout << "    ";
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<"   ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<"   ";}
  cout << endl;
}

// template <typename T>
// void print_pairvec(const vector<T> &v, ll num=0){
//   if(num == 0) num = (ll)v.size();
//   cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
// }
template <typename T>
void print_pairvec(const T &_pair, ll num=0){
  cout << endl; for(pair<ll, int> x: _pair){ cout << x.first << " " << x.second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

int cost(vector<int> vec, int length){
  int res = 0, sum = 0;
  res += ((int)vec.size()-1) * 10;//合成魔法を使う
  for(int x : vec) sum += x;
  res += abs(length - sum);
  // cout << "  res: " << res << endl;
  return res;
}
int main(){
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<int> bamb(N);
  for(int i=0; i<N; i++) cin >> bamb[i];

  const int INF = 1e9+1;
  int ans = INF;
  const int NUM = 16;
  // 4進数全探索
  // 8本をそれぞれをa, b, cノどれに使うか,あるいは使わないかの4通りで全探索 (4^8 = 2^16 = 65536通り) 
  for(int i=0; i<(1<<NUM); i++){
    bitset<NUM> bit(i);// 
    vector<int> a, b, c;
    for(int j=0; j<N; j++){
    if(bit[j] == 0  &&  bit[j+N] == 0) a.push_back(bamb[j]);
    if(bit[j] == 0  &&  bit[j+N] == 1) b.push_back(bamb[j]);
    if(bit[j] == 1  &&  bit[j+N] == 0) c.push_back(bamb[j]);
    // if(bit[j] == 1  &&  bit[j+1] == 1) ;
    }
    if((int)a.size()==0) continue;
    if((int)b.size()==0) continue;
    if((int)c.size()==0) continue; //これがないと 入力例3でcが0の長さの木から+1を100回くりかえす
    int yen = 0;
    yen += cost(a, A);
    yen += cost(b, B);
    yen += cost(c, C);
    ans = min(ans, yen);

    // if(yen == 110){
    //   cout << " A: " << A; cout << " a: "; print_vec(a);
    //   cout << " B: " << B; cout << " b: "; print_vec(b);
    //   cout << " C: " << C; cout << " c: "; print_vec(c);
    // }
    // if(yen == 110) cout << " ans: " << ans << " i: " << i << " bit: " << bit << " yen: " << yen << endl;
  }
  cout << ans << endl;
  return 0;
}
