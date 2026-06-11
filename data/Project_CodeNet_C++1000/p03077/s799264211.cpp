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
#include <regex>
#include <initializer_list>
#include <deque> 
#define DBL_MIN 0.000000000000001

#include <iostream>
using namespace std;


int main(void){
    long N,A,B,C,D,E;
    cin >> N >> A >> B >> C >> D >> E;
    long min_p = min(A,min(B,min(C,min(D,E))));
    long bottle = N / min_p + ( N % min_p > 0);
    cout << bottle + 4 << endl;
}

