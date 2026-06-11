#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    string s;
    cin >> s;
    ull K;
    cin >> K;
    int one_continue_n = 0;
    int a;
    for(char c : s){
        if(c != '1'){
            a = c - '0';
            break;
        }else one_continue_n++;
    }
    if(one_continue_n >= K) cout << '1' << endl;
    else cout << a << endl;
}