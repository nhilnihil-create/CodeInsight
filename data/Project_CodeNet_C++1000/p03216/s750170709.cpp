#include <bits/stdc++.h>
using namespace std;

int n;
string s;
long long mc_acc[1000001], m_acc[1000001], c_acc[1000001];

long long solve(int len) {
  long long ans = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'D') {
      ans += mc_acc[min(i+len, n)] - mc_acc[i] - m_acc[i] * (c_acc[min(i+len, n)] - c_acc[i]);
    }
  }
  return ans;
}
int main() {
  cin>>n;
  cin>>s;
  m_acc[0] = 0;
  for (int i=0; i<n; i++) {
    m_acc[i+1]= m_acc[i];
    if (s[i] == 'M') {
      ++m_acc[i+1];
    }
  }
  c_acc[0] = 0;
  mc_acc[0] = 0;
  for (int i=0; i<n; i++) {
    c_acc[i+1] = c_acc[i];
    mc_acc[i+1] = mc_acc[i];
    if (s[i] == 'C') {
      mc_acc[i+1] += m_acc[i];
      ++c_acc[i+1];
    }
  }

  int q;
  cin>>q;
  for (int i=0; i<q; i++) {
    int k;
    cin>>k;
    cout<<solve(k)<<endl;
  }
}