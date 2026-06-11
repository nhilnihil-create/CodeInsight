#define Debug
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define ll long long int
#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define outi(a) printf("%lld\n",(a))
using namespace std;
ll read()
{
  char c = getchar();
  while((c < '0' || c > '9') && c != '-')
  c = getchar();
  ll isk = 1;
  if(c == '-') isk = -1,c = getchar();
  ll sum = 0;
  while(c >= '0' && c <= '9')
  sum = sum*10 + c - '0', c = getchar();
  return sum*isk;
}
int main()
{
  //freopen("input.txt", "r", stdin);
  int arr[3];
   arr[0] = read(), arr[1] = read() , arr[2]= read();
   sort(arr, arr+3);
   ll sum = 0;
   rep1(i,3)
   sum += arr[i] - arr[i-1];
   cout << sum << endl;

}
