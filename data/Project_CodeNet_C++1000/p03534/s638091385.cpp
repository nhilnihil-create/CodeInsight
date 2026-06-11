#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair <int,ll> pii;
typedef vector<int> vi;
vi charcnt(3);
string s;
int main(void)
{
  cin >> s;
  for(int i=0;i<s.size();i++)
    {
      if(s[i]=='a') charcnt[0]++;
      else if(s[i]=='b') charcnt[1]++;
      else charcnt[2]++;
    }
  if(abs(charcnt[0]-charcnt[1])<=1 && abs(charcnt[1]-charcnt[2])<=1 && abs(charcnt[0]-charcnt[2])<=1)
    {
      cout << "YES" << endl;
      return 0;
    }
  else 
    {
      cout << "NO" << endl;
      return 0;
    }
}


