#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  if(s.size()==2){
    cout<<s<<endl;
  }else{
    cout<<s[2]<<s[1]<<s[0]<<endl;
  }
}
