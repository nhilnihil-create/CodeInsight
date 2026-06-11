#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll pref[101000];
ll suff[101000];
ll ara[101000];
int main()
{
  int b , r;
  cin >> b;
  map<string,int>blu,red;
  vector<string>v;
  for(int i=0; i<b; i++)
  {
      string s;
      cin >> s;
      blu[s]++;
      if(blu[s]==1)
        v.push_back(s);

  }
  int mx = 0 ;
  cin >> r;
  for(int i=0; i<r; i++)
  {
      string s;
      cin >> s;
      red[s]++;

  }

  for(int i=0; i<v.size(); i++)
  {
      mx = max(mx,blu[v[i]]-red[v[i]]);
  }
  cout << mx << endl;

 }
