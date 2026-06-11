#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;
  cin >> n;
  int pren;
  int pres;
  string res;
  cout << 0 << endl;
  cin >> res;
  if(res != "Vacant")
  {
    if(res == "Male")
    {
      pres = 0;
      pren = 0;
    }
    if(res == "Female")
    {
      pres = 1;
      pren = 0;
    }
    int left = 1;
    int right = n-1;
    while(left<=right)
    {
      int cent = (left+right)/2;
      cout << cent << endl;
      cin >> res;
      if(res == "Vacant") break;
      int nres;
      if(res == "Male") nres = 0;
      if(res == "Female") nres = 1;
      int dis = abs(cent-pren);
      if(pres == nres && dis%2==0 || pres != nres && dis%2 != 0)
      {
        left = cent+1;
      }
      else
      {
        right = cent-1;
      }
    }
  }
}