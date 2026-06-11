#include <iostream>
#include <iomanip>
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
#define POWER9 1000000000
#define MOD POWER9+7
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define LL_MIN (LL)-9223372036854775807
#define LL_MAX (LL)9223372036854775807
#define PI 3.14159265359

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(9);
    
    int N;
    cin >> N;
    int t[100],v[100];
    int sum = 0;
    for(int i=0; i<N; i++){
        cin >> t[i];
        sum += t[i];
    }
    for(int i=0; i<N; i++) cin >> v[i];
    int all[20001];
    for(int i=0; i<=sum; i++) all[i] = min(i, sum-i);
    int now = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<=now; j++) all[j] = min(all[j], v[i]+now-j);
        for(int j=now; j<=now+t[i]; j++) all[j] = min(all[j], v[i]);
        now += t[i];
        for(int j=now; j<=sum; j++) all[j] = min(all[j], j-now+v[i]);
    }

    //for(int i=0; i<=sum; i++) cout << i << " " << all[i] << endl;
    double ans = 0;
    int tmp = 0;
    now = 0;
    for(int i=0; i<sum; i++){
        ans += (double)(all[i] + all[i+1]) / 2;
        if(all[i] == all[i+1] && all[i] < v[now]) ans += 0.25;
        tmp++;
        if(tmp == t[now]){
            tmp = 0;
            now++;
        }
    }
    cout << ans << endl;

    return 0;
}