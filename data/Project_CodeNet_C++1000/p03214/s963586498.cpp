#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;
# define maxn 100000
int main() {
  int n ,a[maxn],sum(0);
  cin>>n;
  for (int i(0);i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  double ave= (double)sum/n;
  double min=abs(a[0]-ave);
  int out(0);
  for (int i(n-1);i>=0;i--){
    if (min>=abs(a[i]-ave)){
      min=abs(a[i]-ave);
      out=i;
    }
  }
  cout<<out;
}