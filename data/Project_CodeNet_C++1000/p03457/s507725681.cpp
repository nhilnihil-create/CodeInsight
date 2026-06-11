#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<int> time(N);
    vector<vector<int>> data(N, vector<int>(2));// data[i][0] = x , data[i][1] = y
    //
    for(int i=0;i<N;i++){
        cin >> time[i] >> data[i][0] >> data[i][1];
    }
    //
    bool bre = false;
    //
    for(int i=0;i<N;i++){
        int dist;
        if(i==0){
            dist = abs(data[i][0]) + abs(data[i][1]);
        }
        else{
            dist = abs(data[i][0]-data[i-1][0]) + abs(data[i][1]-data[i-1][1]);
        }
        // time
        int bw_time;
        if(i==0){
            bw_time = time[i];
        }
        else{
            bw_time = time[i] - time[i-1];
        }
        //
        for(int j=bw_time;j>=-1;j=j-2){
            if(j==dist){
                break;
            }
            else if(j<=0){
                bre = true;
                break;
            }
        }
        if(bre){
            break;
        }
    }
    //
    if(bre){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}