#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){
int n;
cin >> n;

int a, b, c;
a = n/100;
b = n/10-a*10;
c = n%100-b*10;

if (a ==1 ) a=9;
else if (a ==9 ) a=1;
if (b ==1 ) b=9;
else if (b ==9 ) b=1;
if (c ==1 ) c=9;
else if (c ==9 ) c=1;
  int ans =a*100+b*10+c ;
cout << ans << endl;
}