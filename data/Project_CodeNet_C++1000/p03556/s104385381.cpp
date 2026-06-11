/**
 *  author:   TakeruOkuyama
 *  created:  2020-04-15 11:17:28
**/
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int INF = 999999999;

int main(){
    int N;
    cin >> N;
    for(int i = 40000;;i--){
        if(i*i <= N){
            cout << i*i << endl;
            return 0;
        }
    }
return 0;}
/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 