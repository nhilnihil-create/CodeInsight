#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main(){
  int N;cin>>N;
  vector<P> a_l(N),b_l(N);
  for (int i = 0; i < N; i++) {
    cin>>a_l[i].second>>a_l[i].first;
  }
  for (int i = 0; i < N; i++) {
    cin>>b_l[i].first>>b_l[i].second;
  }
  sort(b_l.begin(),b_l.end());
  sort(a_l.begin(),a_l.end(),greater<P>());
  vector<bool> check(N, false);
  int cnt=0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(a_l[j].second<b_l[i].first&&a_l[j].first<b_l[i].second&&!check[j]){
        check[j]=true;
        cnt++;
        break;
      }
    }
  }
  cout<< cnt  << "\n";
}