#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <array>
#include <cmath>
#include <random>
#include <functional>
#include <climits>
using namespace std;
using lint=long long;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  cout<<((a+b==15)?  '+' : (a*b==15)? '*' : 'x')<<endl;
  return 0;
}
