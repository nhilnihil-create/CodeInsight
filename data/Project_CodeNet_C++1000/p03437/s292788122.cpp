#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

const long long INF = 100000000000000000;

int main()
{
  long long a, b;
  cin >> a >> b;
  if(a%b==0){
    cout << -1 << endl;
  }
  else{
    cout << a << endl;
  }
}
