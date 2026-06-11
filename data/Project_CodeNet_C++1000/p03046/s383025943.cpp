#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  long long m, k;
  cin>>m>>k;
  if (m == 1) {
    if (k == 0) {
      cout<<"0 0 1 1"<<endl;
    } else {
      cout<<-1<<endl;
    }
  } else if (k > (1LL << m) - 1) {
    cout<<-1<<endl;
  } else {
    vector<int> v;
    for (int i=0; i<(1<<m); i++) {
      if (i != k) {
        v.push_back(i);
      }
    }
    v.push_back(k);
    for (int i=(1<<m)-1; i>=0; i--) {
      if (i != k) {
        v.push_back(i);
      }
    }
    v.push_back(k);
    for (int i=0; i<v.size(); i++) {
      cout<<v[i];
      if (i != v.size() - 1) {
        cout<<" ";
      }
    }
    cout<<endl;
  }
}