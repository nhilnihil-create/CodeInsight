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

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
const int inf=1e6;
int k,dist[100000];
deque<int> todo;
int main(){
	cin>>k;
	for (int i=0;i<k;i++) dist[i]=inf;
	dist[1]=1;todo.push_back(1);
	while(!todo.empty()){
		int x=todo.front();todo.pop_front();
		if (dist[(10*x)%k]>dist[x]){
			dist[(10*x)%k]=dist[x];
			todo.push_front((10*x)%k); 
		}
		if (dist[(x+1)%k]>dist[x]+1){
			dist[(x+1)%k]=dist[x]+1;
			todo.push_back((x+1)%k); 
		}
	}
	cout<<dist[0];
}