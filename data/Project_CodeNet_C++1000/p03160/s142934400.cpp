#include <bits/stdc++.h>
using namespace std;
int *min_arr;
void updateMin(int i, int w)
{
   if(w < min_arr[i])
   {
      min_arr[i] = w;
   }
}
int main()
{
   int n;

   cin >> n;
   min_arr = new int[n];
   int weight[n];
   for(int i = 0; i < n; i++) {
      cin >> weight[i];
   } 
   
   for (int i = 0; i < n; i++) min_arr[i] = INT_MAX;

   //build 2d array
   for(int i = 0; i < n; i++)
   {
      if (i == 0)
      {
         min_arr[0] = 0;
         // mat[0][0] = 0;
      } 
      
      // frog jump first case
      if(i + 1 < n)
      {
         updateMin(i + 1, abs(weight[i] - weight[i + 1]) + min_arr[i]);
      }
      // frog jump second case
      if (i + 2 < n)
      {
         updateMin(i + 2, abs(weight[i] - weight[i + 2]) + min_arr[i]);
      }
   }
   cout << min_arr[n-1] << endl;
}