#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int main(void){
    int N,T;
    cin >> N >> T;
    int c[N],t[N];
    for(int i=0;i<N;i++) cin >> c[i] >> t[i];
    
    long long min_c = INF;
    
    for(int i=0;i<N;i++){
        if(t[i]<=T){
            if(min_c>c[i]) min_c = c[i];
        }
    }
    
    if(min_c==INF) cout << "TLE";
    else cout << min_c;
    
    return 0;
}
