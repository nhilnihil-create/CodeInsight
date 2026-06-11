#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  string s;
  cin >> s;
  int slen = s.size();
  vector<char> zero(slen);
  vector<char> one(slen);
  int zerocnt = 0;
  int onecnt = 0;
  for(int i = 0; i < slen; i++)
  {
    zero[i] = '0' + i % 2;
    one[i] = '0' + (i + 1 ) % 2;
    if(zero[i] != s[i])
    {
      zerocnt++;
    }
    if(one[i] != s[i])
    {
      onecnt++;
    }
  }
  cout << min(zerocnt, onecnt) << endl;
}