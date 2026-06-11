#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, m;
   cin >> n;
   vector<string>s(n);
   for(int i = 0; i < n; i++) cin >> s[i];
   cin >> m;
   vector<string>t(m);
   for(int i = 0; i < m; i++) cin >> t[i];
   int count = 1;
   int max = 0;
   for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
         if(s[i] == s[j])count++;
      }
      for(int j = 0; j < m; j++){
         if(s[i] == t[j])count--;
      }
      if(max < count)max = count;
      count = 1;
   }
   cout << max << endl;
}
