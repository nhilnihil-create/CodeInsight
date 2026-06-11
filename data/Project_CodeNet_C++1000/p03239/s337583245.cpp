#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

int main(void){
    int N,T;
    cin >> N >> T;
    int c[N],t[N];
    for(int i=0;i<N;i++){
        cin >> c[i] >> t[i];
    }
    int ans = 100000000;
    for(int i=0;i<N;i++){
        if(t[i] <= T){
            ans = min(ans,c[i]);
        }
    }
    if(ans == 100000000){
        cout << "TLE" << endl;
        return 0;
    }
    cout << ans << endl;;
}
