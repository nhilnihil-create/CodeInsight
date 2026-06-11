//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
//container util
//------------------------------------------

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define VECMAX(x) *max_element(ALL(x))
#define VECMIN(x) *min_element(ALL(x))
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MULTIPLE(i,n,k) for(int i = (k) ; i<(n) ; i+=k+1)//倍数ループ
//constant
//------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;






#define SIZEOF(x) sizeof(x)/sizeof(x[0])




template <class T>
T max(T *a , LL n){
    T maxi = a[0];
    for(LL i = 0; i < n; ++i){
        if(a[i] > maxi)maxi = a[i];
    }
    return maxi;
}

template <class T>
T maxfrag(T *a , LL n){
    T maxi = a[0];
    T frag = 0;
    for(LL i = 0; i < n; ++i){
        if(a[i] > maxi){
            maxi = a[i];
            frag = i;
        }
    }
    return frag;
}


template <class T>
T min(T *a , LL n){
    T mini = a[0];
    for(LL i = 0; i < n; ++i){
        if(a[i] < mini)mini = a[i];
    }
    return mini;
}

template <class T>
T minfrag(T *a , LL n){
    T mini = a[0];
    T frag = 0;
    for(LL i = 0; i < n; ++i){
        if(a[i] < mini){
            mini = a[i];
            frag = i;
        }
    }
    return frag;
}


template <class T>
T sum(T *a , LL n){
    T s=0;
    for(LL i = 0; i < n; ++i){
       s+=a[i]; 
    }
    return s;
}

#define MAX(x) max(x,SIZEOF(x))
#define MIN(x) min(x,SIZEOF(x))
#define SUM(x) sum(x,SIZEOF(x))




int main(){
    LL a, b;
    cin >> b >> a;
    LL redcount = 0;
    LL bluecount = 51;


    char board[10000];

    REP(i , 10000){
        if(i%100<50)board[i] = '.';
        else board[i] = '#';
    }
    LL Rcount = 1;
    LL Bcount = 1;


    while(Rcount < a){
        board[redcount] = '#';
        redcount += 2;
        if(redcount % 100 == 50){
            redcount += 150;
        }
        Rcount += 1;
    }


    while(Bcount < b){

        board[bluecount] = '.';

        bluecount += 2;
        if(bluecount % 100 == 1){
            bluecount += 150;
        }
        Bcount += 1;
    }
    cout << 100 <<" " << 100 << "\n";
    REP(i , 10000){
        cout << board[i];
        if(i%100==99 && i!=9999)cout << "\n";
    }


    

    
    return 0;

}