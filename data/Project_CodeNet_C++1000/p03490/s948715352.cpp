#include <bits/stdc++.h>

#define ll long long

#define f first
#define s second

#define pb push_back

using namespace std;

const int N = 3e4 + 10;
const int md = 1e9 + 9;

string s;

int n;

int gox[N][2];
int goy[N][2];

int x, y;

int cnt[N];

int sz;

int add = 8000;

int main() {
 cin >> s;
 cin >> x >> y;
 for (auto smb : s) {
  if (smb == 'F') {
   ++cnt[sz];
   continue;
  }
  ++sz;
 }
 gox[add + cnt[0]][0] = 1;
 for (int i = 2; i <= sz; i += 2) {
  for (int j = 0; j <= add + add; j++) {
   gox[j][1] = (gox[j - cnt[i]][0] | gox[j + cnt[i]][0]);
  }
  for (int j = 0; j <= add + add; j++) {
   gox[j][0] = gox[j][1];
  }
 }
 goy[add][0] = 1;
 for (int i = 1; i <= sz; i += 2) {
  for (int j = 0; j <= add + add; j++) {
   goy[j][1] = (goy[j - cnt[i]][0] | goy[j + cnt[i]][0]);
  }
  for (int j = 0; j <= add + add; j++) {
   goy[j][0] = goy[j][1];
  }
 }
 if (gox[add + x][0] & goy[add + y][0])
  cout << "Yes";
 else
  cout << "No";
 return 0;
}
