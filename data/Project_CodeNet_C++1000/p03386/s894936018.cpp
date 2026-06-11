#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <numeric>
#include <float.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long ll;
// 最大公約数求める関数
int my_gcd(int n , int m){
  if(n < m){
    int tmp = n;
    n = m;
    m = tmp;
  }
  int l  = n % m;
  while(l != 0){
    n = m;
    m = l;
    l = n % m;
}
return m;
}

//char⇒int関数
 int ctoi(char c) {
 	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}



int main(){
	int A,B,K; cin >> A >> B >> K;
	set<int> s;
	int a,b; a = A; b = B;
	rep(i,K){
		if(A > B) break;
		s.insert(A);
		A++;
		s.insert(B);
		B--;
		
	}

	for(int i = a; i <= a + K; i++){
		if(s.count(i)){
			cout << i << endl;
			s.erase(i);
		}
	}
	for(int i = b-K; i <= b ; i++){
		if(s.count(i)){
			cout << i << endl;}
	}
}