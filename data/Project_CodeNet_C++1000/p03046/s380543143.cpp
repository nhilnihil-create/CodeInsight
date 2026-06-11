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
//変数デバッグ
#define DEB(variable) cout << #variable << '=' << variable << endl

//for簡易表記(引数ミス防止)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){

    long long int m,k;
    cin>>m>>k;
    if(k>=(long long int)pow(2,m)){
        cout << "-1" << endl;
        return 0;
    }else if(m==0){
        if(k==0){
            cout << "0 0" << endl;
        }else{
            cout << "-1" << endl;
        }
        return 0;
    }else if(m==1){
        if(k==0){
            cout << "0 0 1 1" << endl;
        }else{
            cout << "-1" << endl;
        }
        return 0;
    }else{
        REP(i,(long long int)pow(2,m)){
            if(i!=k){
                cout << i << " ";
            }
            
        }
        cout << k << " ";
        DEFOR(i,(long long int)pow(2,m),0){
            if(i!=k){
                cout << i << " ";
            }
        }
        cout << k << endl;
    }

    return 0;
}
