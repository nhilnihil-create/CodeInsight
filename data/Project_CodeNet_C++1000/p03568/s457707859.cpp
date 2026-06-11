#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int ok=1,ng=1;
    for (int i=0;i<N;++i){
        int A; cin >> A;
        ok*=3; ng*=(A&1?1:2);
    }
    cout << ok-ng << '\n';
}