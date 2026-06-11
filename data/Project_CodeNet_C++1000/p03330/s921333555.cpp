#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,c,z=0,o=0,t=0,ans=99999999999999999;
  cin >> n >> c;
  vector<vector<long>> d(c,vector<long>(c));
  vector<long> ze(c);
  vector<long> on(c);
  vector<long> tw(c);
  vector<long> z_iwakan(c);
  vector<long> o_iwakan(c);
  vector<long> t_iwakan(c);
  for(long i=0;i<c;i++) for(long j=0;j<c;j++) cin >> d[i][j];
  for(long i=0;i<n;i++) {
    for(long j=0;j<n;j++) {
      long a;
      if((i+j)%3==0) {
        z++;
        cin >> a;
        ze[a-1]++;
      } else if((i+j)%3==1) {
        o++;
        cin >> a;
        on[a-1]++;
      } else {
        t++;
        cin >> a;
        tw[a-1]++;
      }
    }
  }

  for(long i=0;i<c;i++) {
    for(long j=0;j<c;j++) {
      z_iwakan[i]+=d[j][i]*ze[j];
    }
  }
  for(long i=0;i<c;i++) {
    for(long j=0;j<c;j++) {
      o_iwakan[i]+=d[j][i]*on[j];
    }
  }
  for(long i=0;i<c;i++) {
    for(long j=0;j<c;j++) {
      t_iwakan[i]+=d[j][i]*tw[j];
    }
  }

  for(long i=0;i<c;i++) {
    for(long j=0;j<c;j++) {
      for(long k=0;k<c;k++) {
        if((i!=j&&i!=k)&&j!=k) {
          ans=min(ans,z_iwakan[i]+o_iwakan[j]+t_iwakan[k]);
        }
      }
    }
  }
  cout << ans << endl;
}