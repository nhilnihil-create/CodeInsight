#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
      ll n;
      cin >> n;
      map<char,int> mp;
      int cnt = 0;
      for(int i=0; i<n; i++)
      {
          char val;
          cin >> val;
          if(!mp[val])cnt++;
          mp[val]++;

      }
      if(cnt==3)cout << "Three" << endl;
      else cout << "Four" << endl;
}
