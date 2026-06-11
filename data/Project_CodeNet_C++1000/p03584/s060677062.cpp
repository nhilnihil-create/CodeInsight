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

using namespace std;

int A[100000];
long long B[100000];
bool stand_bit(int N, int pos){
    if((((N >> (29 - pos)) & 1) == 0)){
        return false;
    }
    return true;
}
bool valid(int cond, int K, int same_till){
    for(int i = 0; i < same_till; i++){
        if(!stand_bit(K, i) && stand_bit(cond, i)){
            return false;
        }
    }
    if(same_till < 30){
        return !stand_bit(cond, same_till);
    } 
    return true;
}

int main(){
    int N;
    int K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    long long ans = 0;
    bool stated = false;
    for(int i = 0; i < 31; i++){
        if((i == 30 || (K >> (29 - i)) & 1) == 1){
            long long tmp_ans = 0;
            for(int j = 0; j < N; j++){
                if(valid(A[j], K, i)){
                    tmp_ans += B[j];
                }
            }
            ans = max(ans, tmp_ans);
        }
    }
    cout << ans << endl;
    return 0;
}
