#include <bits/stdc++.h>
using namespace std;
int arr [100009];
int dp [100009];
int n,k;
int frog (int f_index)
{
if (f_index + 1 == n)return 0;
if (dp [f_index] != -1)return dp [f_index];
int s = INT_MAX;
for (int i = 1 ;i <= k;i++)
{
if (f_index + i >= n)break;
s = min (s , frog (f_index + i) + abs (arr [f_index + i] - arr [f_index]));
}
return dp [f_index] = s ;
}
int main ()
{
cin >>n>>k;
for (int p = 0;p < 100009;p++)
{
dp [p] = -1;
}
for (int i = 0 ;i<n;i++)
{
cin >> arr [i];
}
cout <<frog (0)<<'\n';

}