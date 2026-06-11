#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    vector<LL> D(N);
    REP(i,N)cin>>D[i];
    
    int M;
    cin>>M;
    vector<LL> T(M);
    REP(i,M)cin>>T[i];

    map<LL, int> map_num;
    REP(i,N){
        auto itr = map_num.find(D[i]);
        if(itr != map_num.end()){
            map_num[D[i]] += 1;
        }else{
            map_num[D[i]] = 1;
        }
    }

    REP(i,M){
        auto itr = map_num.find(T[i]);
        if(itr != map_num.end()){
            if(map_num[T[i]]==0){
                cout << "NO" << endl;
                return 0;
            }else{
                map_num[T[i]] -= 1;
            }
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    return 0;
}