#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>
 
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()
 
using namespace std;
using ll = long long int;
 
const int inf = 1001001000;
const long long int Inf = 1001001001001001000;
 
template<typename T>
void print(vector<T> a){
	for (auto x:a){
		cout << x << " ";
	}
	cout << endl;
}
 
template<typename T>
void print2d(vector<vector<T>> a){
	for (auto v:a){
		for (auto x:v){
			cout << x << " ";
		}
		cout << endl;
	}
}
 
 
 
int main()
{
	int a, b;
	cin >> a >> b;
	if(a*b==15)
		cout << "*" << endl;
	else if(a+b==15){
		cout << "+" << endl;
	} else {
		cout << "x" << endl;
	}
	return 0;
}