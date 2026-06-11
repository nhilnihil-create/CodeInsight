#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
   char s1,s2,s3;
   cin >> s1 >> s2 >> s3;
   int ans = 0;
   if(s1=='1')ans++;
   if(s2=='1')ans++;
   if(s3=='1')ans++;
   cout << ans <<endl;
}