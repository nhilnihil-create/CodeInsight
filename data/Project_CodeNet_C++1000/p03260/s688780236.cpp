#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int a,b;
cin >> a >>b;
bool ans = false;
for(int i = 1;i<=3;i++){
  if(a*b*i%2!=0)ans = true;
}
puts(ans?"Yes":"No");
}
  
