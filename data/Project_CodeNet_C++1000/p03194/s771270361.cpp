#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    long long int n,p;
    cin>>n>>p;
    long long int max = 1+pow(p, 1 / (n * 1.0));
    long long int i;
    for (i = max; p % ((long long int)pow(i,n)) != 0; i--);
    cout << i << endl;
    return 0;
}
