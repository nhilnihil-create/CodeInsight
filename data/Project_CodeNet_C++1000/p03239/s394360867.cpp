/*
      author  : nishi5451
      created : 14.08.2020 22:05:41
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

const int INF = 2e9;

int main(){
    int n,time;
    cin >> n >> time;
    int cost = INF;
    rep(i,n){
        int c,t;
        cin >> c >> t;
        if(time>=t){
            cost = min(cost,c);
        }
    }
    if(cost == INF){
        cout << "TLE" << endl;
    }
    else{
        cout << cost << endl;
    }
    return 0;
}