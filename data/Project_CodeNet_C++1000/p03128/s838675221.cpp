#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <limits.h>
#include <utility>
#include <stack>

using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair<ll, ll> P;

bool compare(vector<int> x, vector<int> y){
    int xSum = 0, ySum = 0;
    for(int i = 0; i < 9; i++){
        xSum += x[i];
        ySum += y[i];
    }
    if(xSum != ySum){
        return xSum < ySum;
    }
    for(int i = 8; i >= 0; i--){
        if(x[i] == y[i]){
            continue;
        }
        else{
            return x[i] < y[i];
        }
    }
}

vector<int> dp[10100];

int main(){
    int N, M;
    bool check[9];  fill(check, check+9, 0);
    int matchNum[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a; cin >> a;
        check[a-1] = true;
    }

    vector<int> initVec(9, 0);
    dp[0] = initVec;
    for(int i = 0; i < N; i++){
        if(dp[i].empty()){
            continue;
        }
        for(int j = 0; j < 9; j++){
            if(!check[j]){
                continue;
            }
            vector<int> v(9, 0);
            for(int k = 0; k < 9; k++){
                v[k] = dp[i][k];
            }
            v[j]++;
            if(dp[i + matchNum[j]].empty()){
                dp[i+matchNum[j]] = v;
            }
            else if(compare(dp[i+matchNum[j]], v)){
                dp[i+matchNum[j]] = v;
            }
        }
    }

    vector<int> res = dp[N];
    for(int i = 8; i >= 0; i--){
        for(int j = 0; j < res[i]; j++){
            cout << i+1;
        }
    }
    cout << endl;



    return 0;
}