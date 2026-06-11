#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

int N,Q; string s;
char t[200020],d[200020];
int check(int x){
    for (int i = 0; i < Q; i++){
        if (s[x] == t[i]){
            if (d[i] == 'R') x++;
            else x--;
        }
        if (x == -1) return -1;
        if (x == N) return 1;
    }
    return 0;
}

int main(){
    cin >> N >> Q;
    cin >> s;
    
    for (int i = 0; i < Q; i++){
        cin >> t[i] >> d[i];
    }
    int l = -1,r = N,mid;
    while (l < r-1){
        mid = (l+r)/2;
        if (check(mid) == -1){
            l = mid;
        } else {
            r = mid;
        }
    }
    int ch1 = l;
    l = -1,r = N;
    while (l < r-1){
        mid = (l+r)/2;
        if (check(mid) == 1) r = mid;
        else l = mid;
    }
    cout << r - ch1 - 1 << endl;

    //check L
}