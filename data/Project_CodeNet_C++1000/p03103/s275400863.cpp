#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

   ll n, m;
   cin >> n >> m;
   vector<pair<ll, ll> > cans(n);

   for(int i = 0; i < n; i++)
      cin >> cans[i].first >> cans[i].second;
   
   sort(cans.begin(), cans.end());
   ll money = 0l, can_buyed = 0;

   for(int i = 0; i < n; i++){
       ll temp = min(cans[i].second, m - can_buyed);
       money += temp * cans[i].first;
       can_buyed += temp;
   }

   cout << money;
   
   return 0;
}
