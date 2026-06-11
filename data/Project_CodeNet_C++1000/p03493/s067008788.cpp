#include <bits/stdc++.h>

using namespace std;

int main() {
int a,b,ans=0;
cin>>a;

ans+=a/100;
ans+=(a/10)%2;
ans+=a%2;

  cout << ans << endl;
}
