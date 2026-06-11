#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
long long cum_sum_d[1000000];
long long cum_sum_m[1000000];
long long cum_sum_dm[1000000];
//int cum_sum_dmc[1000000];
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    if(S[0] == 'D'){
        cum_sum_d[0] = 1;
    }
    if(S[0] == 'M'){
        cum_sum_m[0] = 1;
    }
    for(int i = 1; i < N; i++){
        cum_sum_d[i] = cum_sum_d[i - 1];
        cum_sum_m[i] = cum_sum_m[i - 1];
        cum_sum_dm[i] = cum_sum_dm[i - 1];
        if(S[i] == 'D'){
            cum_sum_d[i] ++;
        }
        if(S[i] == 'M'){
            cum_sum_m[i] ++;
            cum_sum_dm[i] += cum_sum_d[i];
        }
    }
    for(int i = 0; i < Q; i++){
        int k;
        cin >> k;
        long long ans = 0;
        for(int i = 0; i < N; i++){
            if(S[i] == 'C' && i >= 2){
                long long tmp = cum_sum_dm[i - 1];
                if(i - k >= 0){
                    tmp -= cum_sum_dm[i - k];
                    tmp -= cum_sum_d[i - k] * (cum_sum_m[i - 1] - cum_sum_m[i - k]);
                }
                ans += tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
