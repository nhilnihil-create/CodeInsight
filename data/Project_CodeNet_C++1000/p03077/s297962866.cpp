#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    ll N,A,B,C,D,E;
    cin >> N >> A >> B >> C >> D >> E;
    ll min_dist;
    min_dist = min(A,min(B,min(C,min(D,E))));
    //cout << min_dist << endl;
    
    ll total_time;
    //人の数が少ない
    if(N <= min_dist){
        cout << 5 << endl;
    }else{
        //詰まるところでかかる時間
        ll move_time;
        if(N%min_dist !=0){
            move_time = N/min_dist + 1;
        }else{
            move_time = N/min_dist;
        }
        
        total_time = move_time + 4;
        cout << total_time << endl;
    }
}
