#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
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
//#define NIL -1

int main(){
    LL n;
    vector<vector<int>> f(200, vector<int>(10));
    vector<vector<LL>> p(200, vector<LL>(11));
    vector<int> c(200, 0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            cin >> f[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<11; j++){
            cin >> p[i][j];
        }
    }

    LL tmp_ans;
    LL ans=-2000000000;
    for(int i=1; i<1024; i++){
        int tmp_i = i;
        int idx=0;
        //cout << tmp_i << endl;
        for(int j=0; j<n; j++){
            c[j]=0;
        }
        while(tmp_i>0){
            if(tmp_i&1){
                for(int j=0; j<n; j++){
                    if(f[j][idx]==1){
                        c[j]++;
                    }
                }
            }
            idx++;
            tmp_i >>= 1;
        }
        tmp_ans=0;
        for(int j=0; j<n; j++){
            tmp_ans+=p[j][c[j]];
        }
        if(tmp_ans>ans){
            ans=tmp_ans;
        }
    }

    cout << ans << endl;

    return 0;
}
