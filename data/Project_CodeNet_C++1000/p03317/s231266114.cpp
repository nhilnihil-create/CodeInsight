#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <math.h>
#include <list>
#include <bits/stdc++.h>

using namespace std;

int main(void){
  double N ,L;
  cin >> N >> L;

  cout << ceil((N-1) / (L-1)) << endl;
  return 0;
}