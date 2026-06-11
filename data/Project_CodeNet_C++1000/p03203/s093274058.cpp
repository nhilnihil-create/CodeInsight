#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <cassert>
using namespace std;
#define LL long long
#define MP(a, b) make_pair(a, b)
#define MMP(a, b, c) make_pair(make_pair(a, b), c)
#define MAX 1000000000
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807
#define PI 3.14159265359

int main(){
    iostream::sync_with_stdio(false);
    
    int H,W,N;
    cin >> H >> W >> N;
    swap(W,H);
    vector<int> jama[200000];
    set<pair<int,int> > ojama;
    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        jama[y].push_back(x);
        ojama.insert(MP(x,y));
    }
    for(int i=0; i<H; i++){
        jama[i].push_back(W);
        sort(jama[i].begin(), jama[i].end());
    }

    int ans = INT_MAX;
    int X = 0; int Y = 0;
    while(Y < H && X < W){
        if(ojama.count(MP(X,Y)) == 1) break;
        int tmp = *upper_bound(jama[Y].begin(), jama[Y].end(), X);
        ans = min(ans, tmp);
        if(ojama.count(MP(X+1,Y)) == 1) break;
        X++;
        if(ojama.count(MP(X,Y+1)) == 0) Y++;
    }
    cout << ans << endl;
    
    return 0;
}
