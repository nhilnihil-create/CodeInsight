#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
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

#define ll long long
#define rep(i,n) for(int i=1;i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)
#define pii pair<int,int>
#define mp make_pair

const ll INF=1e9+7;
int len;
int n;
int a[200001];
int le;
//int maxf=-1;
int r;
int l;
bool check(int col){
//	cout<<col<<endl;
	vector<pii> q;
	len=0;
	rep(i,n){
		if(len<a[i]){
			if(!q.empty()&&q.back().first==1){
				q.back().second+=a[i]-len;
			}
			else{
				q.push_back(mp(1,a[i]-len));
			}
			len=a[i];
		}
		else{
			while(len>a[i]){
				if(len-q.back().second>=a[i]){
					len-=q.back().second;
					q.pop_back();
				}
				else{
					q.back().second-=len-a[i];;
					len=a[i];
				}
			}
			le=0;
			if(q.back().first==col){
				le=q.back().second;
				q.pop_back();
			}
			if(q.empty()){
				return 0;
			}
			if(q.back().second==1){
				if(q.size()>=2){
					int c=q.back().first;
					q.pop_back();
					if(q.back().first==c+1){
						q.back().second++;
					}
					else{
						q.push_back(mp(c+1,1));
					}
				}
				else{
					q.back().first++;
				}
			}
			else{
				q.back().second--;
//				cout<<q.back().first<<' '<<"hhh"<<' '<<q.back().first+1<<' ';
//				int t=q.back().first;
//				t++;
				q.push_back(mp(q.back().first+1,1));
//				q.back().first++;
//				cout<<q.back().second<<endl;
			}
			if(le){
				q.push_back(mp(1,le));
			}
			len=a[i];
		}
		/*vector<pii> c;
		while(!q.empty()){
			c.push_back(q.back());
			q.pop_back();
		}
		while(!c.empty()){
			q.push_back(c.back());
//			rep(j,c.back().second){
//				cout<<c.back().first<<' ';
//			}
			cout<<c.back().first<<' '<<c.back().second<<' '<<"hhh"<<' ';
			c.pop_back();
		}
		cout<<endl;*/
	}
	return 1;
}
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n;
	rep(i,n){
		cin>>a[i];
//		maxf=max(maxf,a[i]);
	}
	l=1;
	r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
//			cout<<l<<' '<<r<<' '<<mid<<' '<<1<<endl;
			r=mid;
		}
		else{
//			cout<<l<<' '<<r<<' '<<mid<<' '<<0<<endl;
			l=mid+1;
		}
	}
	cout<<(l+r)/2;
	return 0;
}