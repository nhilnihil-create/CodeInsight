#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long a,b,k;
  cin >> k >> a >> b;
  long long res;
  if(k<a)res = k+1;
  else{
    if(a+2>=b)res=k+1;
    else{
      k-=(a-1);
      res = (k/2)*b-(k/2-1)*a+k%2;
    }
  }
  cout << res << endl;
}
void solve2(){
  int n;
  cin >> n;
  vector<long long>a(n);
  vector<long long>b(n);
  vector<long long>to_change(0);
  vector<long long>to_lower(0);
  long long k=0;
  long long min_c = 0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    k += a[i];
  }
  for(int i=0;i<n;i++){
    cin >> b[i];
    if(b[i]>a[i]){
      to_change.push_back(i);
      min_c += b[i];
    }else{
      min_c += a[i];
      to_lower.push_back(a[i]-b[i]);
    }
  }

  sort(to_lower.begin(),to_lower.end(),greater<int>());

  if(min_c <= k)cout << to_change.size() << endl;
  else{
    int cnt = 0;
    bool done = false;
    for(int i=0;i<to_lower.size();i++){
      min_c-=to_lower[i];
      cnt++;
      if(min_c <= k){
        done = true;
        break;
      }
    }
    if(done)cout << to_change.size()+cnt << endl;
    else cout << -1 << endl;
  }

}
int main(){
  solve2();
  return 0;
}
