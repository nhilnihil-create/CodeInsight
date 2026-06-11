#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    LL c;
    cin >> n >> c;
    vector<vector<LL>> d(c,vector<LL>(c));
    for(LL i=0; i<c; i++){
        for(LL j=0; j<c; j++){
            cin >> d[i][j];
        }
    }
    vector<vector<LL>> c_div(3);
    vector<vector<pair<LL,LL>>> c_sum(3, vector<pair<LL,LL>>(c));
    LL tmp;
    LL tmp_div;
    for(LL i=0; i<n; i++){
        for(LL j=0; j<n; j++){
            tmp_div=(i+j)%3;
            cin >> tmp;
            tmp--;
            c_div[tmp_div].push_back(tmp);
        }
    }
    for(LL i=0; i<3; i++){
        for(LL j=0; j<c; j++){
            c_sum[i][j].first=0;
            c_sum[i][j].second=j;
            for(LL k=0; k<c_div[i].size(); k++){
                c_sum[i][j].first+=d[c_div[i][k]][j];
            }
        }
    }

    sort(c_sum[0].begin(),c_sum[0].end());
    sort(c_sum[1].begin(),c_sum[1].end());
    sort(c_sum[2].begin(),c_sum[2].end());
    LL c_max=NIL;
    LL tmp_sum;
    for(LL i=0; i<3; i++){
        for(LL j=0; j<3; j++){
            for(LL k=0; k<3; k++){
                if(c_sum[0][i].second==c_sum[1][j].second || c_sum[0][i].second==c_sum[2][k].second || c_sum[1][j].second==c_sum[2][k].second){
                    continue;
                }
                tmp_sum=c_sum[0][i].first+c_sum[1][j].first+c_sum[2][k].first;
                if(c_max==NIL){
                    c_max=tmp_sum;
                }else{
                    c_max=min(c_max,tmp_sum);
                }
            }
        }
    }

    cout << c_max << endl;

    return 0;
}
