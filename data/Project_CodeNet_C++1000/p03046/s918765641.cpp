#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 10000000000000000
#define MAX 200001
#define MOD 1000000007  

int main(){
    int M, K;
    cin >> M >> K;
    if(K == 0){
        for(int i = 0; i < pow(2,M); i++){
            if(i != pow(2,M) - 1) cout << i << ' ' << i << ' ';
            else cout << i << ' ' << i << endl;
        }
    }
    else if(K <= pow(2, M) - 1 && M != 1){
        for(int i = 0; i < pow(2,M); i++){
            if(i == K) continue;
            cout << i << ' ';
        }
        cout << K << ' ';
        for(int i = pow(2,M)-1; i >= 0; i--){
            if(i == K) continue;
            cout << i << ' ';
        }
        cout << K << endl;
    }
    else{
        cout << - 1 << endl;
    }
}