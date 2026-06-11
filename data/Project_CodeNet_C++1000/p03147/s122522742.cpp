#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    vector<int> h(N);
    REP(i,N)cin>>h[i];

    int count = h[0];
    FOR(i,1,N){
        if(h[i] - h[i-1] >= 0){
            count += h[i] - h[i-1];
        }
    }

    cout << count << endl;
    return 0;
    
}