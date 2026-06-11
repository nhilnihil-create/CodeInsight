#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
#include <deque>
using ll = long long;
using Graph = vector<vector<int>>;
#include <queue>
#include <stack>
#include <cmath>


bitset<1000000> isPrime;
//素数テーブル作成
void makePrimeTable(int n){  
    isPrime = bitset<1000000>(0);//コンストラクタ呼び出し
    //まずはすべて１にする
    for(ll i = 2LL;i <= n;i++) isPrime.set(i);

    //倍数をすべて0にする
    for(ll i = 2LL;i <= n;i++){
        for(ll j = 2 * i;j <= n;j += i){
            //倍数番目をオフにする
            if(isPrime[j]) isPrime.reset(j);
        }
    }
    
}


int main(){

    int N_MAX = 55555;
    makePrimeTable(N_MAX);

    int n;
    cin >> n;

    vector<int> primeSeq;
    int index = 0;
    //N_MAXまでの素数を配列にすべて格納する
    for(int i = 2;i <= N_MAX;i++){
        if(isPrime[i] && i % 5 == 1) primeSeq.push_back(i);
    }

    //指定の長さ分出力する
    for(int i=0;i < n;i++) cout << primeSeq[i] << " ";
    
    return 0;
}