#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1<<18;

vector <int> sdp[sz];

int main()
{
   int n;
   cin >> n;
   int emsk = 1<<n;
   for(int i=0; i<emsk; i++) {
      int x;
      scanf("%d", &x);
      sdp[i].push_back(x);
   }

   for(int i=0; i<n; i++) {
      for(int j=0; j<emsk; j++) {
         if(j & (1<<i)) {
            int k = j ^ (1<<i);
            for(int x : sdp[k]) sdp[j].push_back(x);
            sort(sdp[j].begin(), sdp[j].end(), greater<int>());
            while(sdp[j].size() > 2) sdp[j].pop_back();
         }
      }
   }
   int ans = 0;
   for(int i=1; i<emsk; i++) {
      ans = max(ans, sdp[i][0] + sdp[i][1]);
      printf("%d\n", ans);
   }
}
