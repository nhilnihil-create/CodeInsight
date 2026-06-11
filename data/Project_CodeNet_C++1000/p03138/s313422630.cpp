#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

vector<bool> genbit(ll a){
    vector<bool> r(50);
    for(int i = 0; i < 50; i++){
        r[i] = (a  & (1ll << i));
    }
    return r;
}

ll memo[50][2]; //上位a + 1桁,　なおbは未満フラグ
void init(){
    for (int a = 0; a < 50; ++a) {
        for (int b = 0; b < 2; ++b) {
            memo[a][b] = 0;
        }
    }
}

int main() {
    init();
    ll N,K;
    cin >> N >> K;
    auto bitK = genbit(K);
    ll oneCount[50];
    for (int i = 0; i < 50; ++i) {
        oneCount[i] = 0;
    }
    for(int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        auto b = genbit(tmp);
        for (int j = 0; j < 50; ++j) {
            if(b[j]){
                oneCount[j]++;
            }
        }
    }
    for(int i = 0; i < 50; i++){
        //cout << oneCount[i] <<","<< endl;
    }
    bool judge = false;
    for (int i = 1; i <= 49; ++i) {
        int currentBit = 49 - i;
        if(bitK[currentBit]){
            memo[i][0] = memo[i-1][0] + (N - oneCount[currentBit]) * (1ll << currentBit);
            memo[i][1] = max(memo[i-1][1] + (oneCount[currentBit]) * (1ll << currentBit),memo[i-1][0] + (oneCount[currentBit]) * (1ll << currentBit));
            if(judge){
                memo[i][1] = max(memo[i][1],memo[i-1][1] +  (N - oneCount[currentBit]) * (1ll << currentBit));
            }
            judge = true;
        }else{
            memo[i][0] = memo[i-1][0] + (oneCount[currentBit]) * (1ll << currentBit);
            memo[i][1] = memo[i-1][1] + (oneCount[currentBit]) * (1ll << currentBit);
            if(judge){
                memo[i][1] = max(memo[i][1],memo[i-1][1] +  (N - oneCount[currentBit]) * (1ll << currentBit));
            }
        }
    }
    cout << max(memo[49][0],memo[49][1]) << endl;
}
