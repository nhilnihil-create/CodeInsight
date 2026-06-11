#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
const int MOD=1000000007;
int K,dist[100000];
deque<int> tobo;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >>K;
	for(int i=0;i<K;i++)
	{
		dist[i]=MOD;
	}
	dist[1]=1;
	tobo.push_back(1);
	while(tobo.size())
	{
		int x=tobo.front();
		tobo.pop_front();
		if(dist[(10*x)%K]>dist[x])
		{
			dist[(10*x)%K]=dist[x];
			tobo.push_back((10*x)%K);
		}
		if(dist[(x+1)%K]>dist[x]+1)
		{
			dist[(x+1)%K]=dist[x]+1;
			tobo.push_back((x+1)%K);
		}
	}
	cout <<dist[0];
    return 0;
}