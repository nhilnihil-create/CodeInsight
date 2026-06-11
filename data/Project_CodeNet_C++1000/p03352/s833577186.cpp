#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define int long long
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define _GLIBCXX_DEBUG
int INF = 1e9+7;
unsigned NthDayOfWeekToDay(unsigned n, unsigned dow, unsigned dow1)
{
unsigned day;
if(dow < dow1) dow += 7;
day = dow - dow1;
day += 7 * n - 6;
return day;
}
unsigned DayToWeekNumber(unsigned day)
{
  return (day - 1) / 7 + 1;
}
unsigned AnotherDayOfWeek(unsigned day, unsigned day0, unsigned dow0)
{
  return (dow0 + 35 + day - day0) % 7;
}
using namespace std;
signed main(){
  int X;
  cin>>X;
  vector<int>A(40);
  A[0]=1;
  A[1]=4;
  A[2]=8;
  A[3]=16;
  A[4]=32;
  A[5]=64;
  A[6]=128;
  A[7]=256;
  A[8]=512;
  A[9]=9;
  A[10]=27;
  A[11]=81;
  A[12]=243;
  A[13]=729;
  A[14]=25;
  A[15]=125;
  A[16]=625;
  A[17]=36;
  A[18]=216;
  A[19]=49;
  A[20]=100;
  A[21]=1000;
  A[22]=121;
  A[23]=144;
  A[24]=169;
  A[25]=196;
  A[26]=225;
  A[27]=289;
  A[28]=324;
  A[29]=361;
  A[30]=400;
  A[31]=441;
  A[32]=484;
  A[33]=529;
  A[34]=576;
  A[35]=676;
  A[36]=784;
  A[37]=841;
  A[38]=900;
  A[39]=961;
  sort(A.begin(),A.end());
  rep(i,40){
    if(A[i]>X){
      cout<<A[i-1]<<endl;
      return 0;
    }
  }
  cout<<1000<<endl;
}