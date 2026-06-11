#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
 
int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int,int>> vec(N);
    int mincost = 10000;
    for(int i=0; i<N; i++){
        cin >> vec.at(i).first;
        cin >> vec.at(i).second;
        if(vec.at(i).second <= T){
            mincost = min(mincost, vec.at(i).first);
        }
    }
    if(mincost != 10000){
        cout << mincost << endl;
    }
    else{
        cout << "TLE" << endl;
    }
}