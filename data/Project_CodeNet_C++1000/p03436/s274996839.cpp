//(・ω・)
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, atoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;
const double pi=3.141592653589793238;
int main(){
    int h,w,white=0;
    cin >> h >> w;
    vector<vector<char>> c(h,vector<char>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> c[i][j];
            if(c[i][j]=='.') white++;
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> dist(h,vector<int>(w,-1));
    q.push(make_pair(0,0));
    dist[0][0]=1;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        int ph=p.first,pw=p.second;
        int dh[4]={-1,0,0,1};
        int dw[4]={0,-1,1,0};
        for(int i=0; i<4; i++){
            int H=ph+dh[i],W=pw+dw[i];
            if(H<0 || W<0) continue;
            else if(H>=h || W>=w) continue;
            else if(c[H][W]=='#' || dist[H][W]!=-1) continue;
            else{
                dist[H][W]=dist[ph][pw]+1;
                q.push(make_pair(H,W));
            }
        }
        if(dist[h-1][w-1]!=-1) break;
    }
    if(dist[h-1][w-1]==-1) cout << dist[h-1][w-1] << endl;
    else cout << white-dist[h-1][w-1] << endl;
}

