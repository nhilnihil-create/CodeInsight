#include <bits/stdc++.h>
using namespace std;
int N,x;bitset<4000004> s(1);
main(){cin>>N;
while(N--){int A;cin>>A;x+=A,s|=s<<A;}
++x/=2;while(!s[x])++x;cout<<x;}