#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
#include <math.h>
#include <vector>
//#include <string>
//#include <list>
//#include <deque>
//#include <unordered_map>
typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    vector<LL> x;
    vector<LL> y;
    vector<LL> h;
    LL tmp_x;
    LL tmp_y;
    LL tmp_h;
    LL ans_x;
    LL ans_y;
    LL ans_h;
    LL tmp_ans_h;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tmp_x >> tmp_y >> tmp_h;
        x.push_back(tmp_x);
        y.push_back(tmp_y);
        h.push_back(tmp_h);
    }

    bool cand;
    for(LL i=0; i<=100; i++){
        for(LL j=0; j<=100; j++){
            cand=true;
            int start=0;
            while(true){
                if(h[start]!=0){
                    tmp_ans_h=h[start]+(int)abs(i-x[start])+(int)abs(j-y[start]);
                    break;
                }
                start++;
            }
            for(int k=0; k<n; k++){
                if(h[k]==0 && tmp_ans_h<(int)abs(i-x[k])+(int)abs(j-y[k])){
                    continue;
                }else if(tmp_ans_h!=h[k]+(int)abs(i-x[k])+(int)abs(j-y[k])){
                    cand=false;
                    break;
                }
            }
            if(cand==true){
                ans_x=i;
                ans_y=j;
                ans_h=tmp_ans_h;
                break;
            }
        }
        if(cand==true){
            break;
        }
    }

    cout << ans_x << " " << ans_y << " " << ans_h << endl;

    return 0;
}