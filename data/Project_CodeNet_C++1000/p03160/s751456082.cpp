#include <bits/stdc++.h>
using namespace std;
int dp1 [10000007];
int dp2 [10000007];

int frog ( int i , int n)
{
if ( i == n)return 0;
if (dp1 [i] != -1)return dp1 [i];
int s;
s = abs (dp2 [i] - dp2 [i + 1]) + frog (i + 1 , n);
if (i + 2 <= n)
{
s = min (s , abs (dp2 [i] - dp2 [i + 2]) + frog (i + 2 ,n));

}
return dp1 [i] = s;
}
int main ()
{
//int i;
int n;
cin >> n;
for (int i = 1;i<= n;i++)
{
cin >> dp2 [i];
}
for (int j = 0;j < 10000007;j++)
{
dp1 [j] = -1 ;
}
cout << frog (1 , n)<<'\n';




}