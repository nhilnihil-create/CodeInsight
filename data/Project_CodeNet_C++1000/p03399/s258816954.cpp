#include "bits/stdc++.h"
using namespace std;
 
// GNU C Compiler
//template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
 
 
/*
--------------------------------------------
 
	type
 
--------------------------------------------
*/
using LL = long long;
using ULL = unsigned long long;
//using pair<T1, T2> = p12;
 
/*
--------------------------------------------
 
	container
 
--------------------------------------------
*/
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
 
/*
--------------------------------------------
 
	repetition
 
--------------------------------------------
*/
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a>b)?b:a
#define REP(n) for(int i=0; i<n; i++)
#define REPj(n) for(int j=0; j<n; j++)
#define REPS(i,n) for(int i=0; i<(n); i++)
#define REPinit(a,n) for(int i=a; i<(n); i++)
#define REPinitj(a,n) for(int j=a; j<n; j++)
 
//algorithm
//#define SORT(c) sort((c).begin(),(c).end())
 
/*
--------------------------------------------
 
	constant
 
--------------------------------------------
*/
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
/*
 
	Optimizer
 
*/
//#pragma GCC optimize("Ofast")


/*
 
	Utility Algorithm
 
*/
template <typename T>
void swapAlgorithm(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

LL euclideanAlgorithm(LL a, LL b) {
    LL a_tmp = a;
    LL b_tmp = b;

    if (a_tmp > b_tmp) {
        swapAlgorithm<LL>(a_tmp, b_tmp);
    }

    LL r = a_tmp % b_tmp;
    while (r != 0) {
        a_tmp = b_tmp;
        b_tmp = r;
        r = a_tmp % b_tmp;
    }
    return b_tmp;    
}

LL getLCM(LL a, LL b) {
    return (a * b)/(euclideanAlgorithm(a, b));
}

/*
  Code
*/

double eauclidDistance(pair<double, double>& x1, pair<double, double>& x2) {
  return sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
}

void swap(int& a, int& b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

map<string, int> blueCard;
map<string, int> redCard;

int main(int argc, char const *argv[])
{
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  cout << (min(A,B)+min(C,D)) << endl;

  return 0;
}
