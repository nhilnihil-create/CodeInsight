#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;
#define DEB(variable) cout << #variable << '=' << variable << endl

#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr long long int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    llint a,b,x;
    cin>>a>>b>>x;
    if(a<=x&&x<=a+b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
