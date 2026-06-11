#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;
void tolow(char *a);
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  tolow(&s[k-1]);
  cout<<s<<'\n';
}
void tolow(char *a)
{
  if(*a>='A' && *a<='Z')
    *a+='a'-'A';
}