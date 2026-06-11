#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int D;
long long G;
int ans = INT_MAX;
vector<long long> p(10);
vector<long long> c(10);

int bitSearch(){
    
    for(int i = 0; i < (1 << D); i++){
        
        long long  sum = 0;
        int count = 0;
        bitset<10> bit(i);
        
        // ボーナスポイントを加えるとき
        for(int j = 0; j < D; j++){
            
            int point = 100 * (j + 1); 
            
            if( bit.test(j) ){
                sum += (point * p[j]) + c[j]; // 合計＝（問題の点数　×　問題個数）＋　ボーナスポイント
                count += p[j];
            }
        }
        
        // ボーナスポイントを加えないとき
        for(int j = D - 1; j >= 0; j--){
            
            int point = 100 * (j + 1); 
            
            if( !bit.test(j) ){
                for(int k = 0; k < p[j]; k++){
                    if(sum >= G) break;
                    sum += point;
                    count++;
                }
            }
        }        

        // 最小の個数を求める
        ans = min(ans, count);
    }
    
    return ans;
    
}



int main(void){
    
    cin >> D >> G;
    for(int i = 0; i < D; i++){
        int Q;
        long long bonus;
        cin >> Q >> bonus;
        p[i] = Q;
        c[i] = bonus;
    }
    
    int ans = bitSearch();
    cout << ans << endl;
    
}
