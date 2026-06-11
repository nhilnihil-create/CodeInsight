#include <bits/stdc++.h>
using namespace std;
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

const int sup = 200200;
bool used[26];
map <int,int> mp;


int main(int argc, char *argv[])
{
  string str;
  cin >> str;
  int len = str.size();
  mp[0]=0;
  int mn = 0;
  for (int i = 0; i < len; i++) {
    int c = str[i]-'a';
    used[c]=!used[c];
    int S=0;
    for (int j = 0; j < 26; j++) {
      if(used[j]) S|=1<<j;
    }
    mn = i+1;
    if(mp.count(S)) mn = min(mn,mp[S]+1);

    for (int j = 0; j < 26; j++) {
      if(mp.count(S^(1<<j))){
	mn = min(mn,mp[S^(1<<j)]+1);
      }
    }

    if(!mp.count(S)) {mp[S]=mn;}
    else {mp[S]=min(mp[S],mn);}
  }
  printf("%d\n",mn);
  return 0;
}
