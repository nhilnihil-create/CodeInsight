#include<iostream>
#include<stdio.h>

using namespace std;

int N;
string A,B,C;
int main(){
    cin >> N >> A >> B >> C;
    int ans = 0;
    for(int i=0; i<N; i++) {
        int cnt = 0;
        if( A[i] - B[i] ) cnt++;
        if( A[i] - C[i] ) cnt++;
        if( B[i] - C[i] ) cnt++;
        if( cnt == 3 ) cnt = 2;
        else if( cnt > 0 ) cnt = 1;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}
