#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
  ll N;cin >> N;
  vector<ll> A(N);
  multiset<ll> mst;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    mst.insert(A[i]);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  ll ans = 0;
  for(int i = 0;i < N;i++){
    ll num = 1;
    while(num <= A[i]){
      num *= 2;
    }
    //cout << A[i] << ' ' << num << endl;
    if(num == A[i] * 2){
      if(mst.find(A[i]) != mst.end()){
        mst.erase(mst.find(A[i]));
        if(mst.find(A[i]) != mst.end()){
          ans++;
          mst.erase(mst.find(A[i]));
        }
      }else{
        mst.erase(A[i]);
      }
    }else{
      if(mst.find(A[i]) != mst.end() && mst.find(num-A[i]) != mst.end()){
        ans++;
        mst.erase(mst.find(A[i]));
        mst.erase(mst.find(num-A[i]));
      }else{
        mst.erase(A[i]);
      }
    }
  }
  cout << ans << endl; 
}