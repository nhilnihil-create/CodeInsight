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

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr long long int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;

int main(){
    llint n, kk;
    cin >> n >> kk;
    vector<pair<llint, llint>> ten(n);
    
    REP(i,n){
        cin >> ten[i].first >> ten[i].second;
    }
    llint xmax, xmin, ymax, ymin,tmpnum,result=linf;
    
    REP(i,n){
        REP(j,n){
            REP(k,n){
                REP(l,n){
                    xmax = max(max(ten[i].first,ten[j].first),max(ten[k].first,ten[l].first));
                    xmin = min(min(ten[i].first,ten[j].first),min(ten[k].first,ten[l].first));
                    ymax = max(max(ten[i].second,ten[j].second),max(ten[k].second,ten[l].second));
                    ymin = min(min(ten[i].second,ten[j].second),min(ten[k].second,ten[l].second));
                    tmpnum = 0;
                    REP(m,n){
                        if(xmin<=ten[m].first&&ten[m].first<=xmax&&ymin<=ten[m].second&&ten[m].second<=ymax){
                            tmpnum++;
                        }
                    }
                    if(tmpnum>=kk){
                        result = min(result, (xmax - xmin) * (ymax - ymin));
                    }
                }
            }
        }
    }
    cout << result << endl;

    return 0;
}
