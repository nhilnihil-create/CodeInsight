#include<bits/stdc++.h>
using namespace std;
int minCoins(int coinList[], int n, int value) {
   int coins[value+1];

   if(value == 0)
      return 0;

   coins[0] = 0;

   for (int i=1; i<=value; i++)
      coins[i] = INT_MAX;

   for (int i=1; i<=value; i++) {
      for (int j=0; j<n; j++)
         if (coinList[j] <= i) {
            int tempCoins = coins[i-coinList[j]];
         if (tempCoins != INT_MAX && tempCoins + 1 < coins[i])
            coins[i] = tempCoins + 1;
      }
   }
   return coins[value];
}

int main() {


int coins[100100];
   int ind = 0 ;
   coins[ind++] = 1;





 int value ;


  cin >> value;
   int ans = 6;
   while(ans<=value)
   {
       coins[ind++] = ans;
       ans *= 6 ;
   }
   ans = 9 ;
   while(ans<=value)
   {
       coins[ind++] = ans;
       ans *= 9 ;
   }

   sort(coins,coins+ind) ;

   cout << minCoins(coins, ind, value);

   return 0;
}
