#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int D, N;
    cin >> D >> N;

    long long ans;
    if(N!=100){
        ans = round(pow(100, D))*N;
    }else{
        ans = round(pow(100, D))*(N+1);
    }
    cout << ans << endl;
    return 0;
}
