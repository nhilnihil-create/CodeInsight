 // /*
#include <bits/stdc++.h>
using namespace std;
int dp [100003][4];
int n;
int arr [100003];
int brr [100003];
int crr [100003];
int main ()
{

cin >>n;
for (int i = 0;i<n;i++)

{
cin >> arr [i]>>brr [i]>>crr [i];
}
dp [0][0] = arr [0];
dp [0][1] = brr [0];
dp [0][2] = crr [0];
for (int i = 1;i<n;i++)
{
dp [i][0] = arr [i] + max (dp [i - 1][1] , dp [i - 1][2]);
dp [i][1] = brr [i] + max (dp [i - 1][0] , dp [i - 1][2]);
dp [i][2] = crr [i] + max (dp [i - 1][0] , dp [i - 1][1]);
}
cout << max ({dp [n - 1][0],dp [n - 1][1],dp [n - 1][2]})<<'\n';
}



// */
