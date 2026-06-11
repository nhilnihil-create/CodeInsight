#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N;
    int H,W;
    cin >> N >> H >> W;
    int a = N - H+1;
    int b = N-W +1;
    int ans = a*b;
    cout << ans << endl;
}