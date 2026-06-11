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
	string S;
	cin>>S;
	if(S.at(0)!='k'){
		if(S.at(S.size()-1)=='e'&&S.at(S.size()-2)=='c'&&S.at(S.size()-3)=='n'&&S.at(S.size()-4)=='e'&&S.at(S.size()-5)=='y'&&S.at(S.size()-6)=='e'&&S.at(S.size()-7)=='k')cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else{
		if(S.at(1)!='e'){
			if(S.at(S.size()-1)=='e'&&S.at(S.size()-2)=='c'&&S.at(S.size()-3)=='n'&&S.at(S.size()-4)=='e'&&S.at(S.size()-5)=='y'&&S.at(S.size()-6)=='e')cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return 0;
		}
		if(S.at(2)!='y'){
			if(S.at(S.size()-1)=='e'&&S.at(S.size()-2)=='c'&&S.at(S.size()-3)=='n'&&S.at(S.size()-4)=='e'&&S.at(S.size()-5)=='y')cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return 0;
		}
		if(S.at(3)!='e'){
			if(S.at(S.size()-1)=='e'&&S.at(S.size()-2)=='c'&&S.at(S.size()-3)=='n'&&S.at(S.size()-4)=='e')cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return 0;
		}
		if(S.at(4)!='n'){
			if(S.at(S.size()-1)=='e'&&S.at(S.size()-2)=='c'&&S.at(S.size()-3)=='n')cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return 0;
		}
		if(S.at(5)!='c'){
			if(S.at(S.size()-1)=='e'&&S.at(S.size()-2)=='c')cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return 0;
		}
		if(S.at(1)!='e'){
			if(S.at(S.size()-1)=='e')cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
	}
}