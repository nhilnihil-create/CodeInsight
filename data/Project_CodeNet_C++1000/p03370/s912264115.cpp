#include <bits/stdc++.h>
using namespace std;


int main() {

  int n,x;
  cin>>n>>x;

  int m_sum=0,m_min=1001;
  for(int i=0;i<n;i++){
    int wk;
    cin>>wk;

    m_sum+=wk;
    m_min=min(m_min,wk);
  }

  cout<<n+(x-m_sum)/m_min<<endl;

  return 0;
}

