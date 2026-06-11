#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for (int i = 1; i < (n+1); i++)

int main(){
    int n,ans=0,answer=0;
    cin >> n;
    rep(i,n){
        if(i%2 == 1){ 
        rep(j,i) {if(i%j == 0) ans++;}}
        if(ans==8) answer++;
        ans=0;
    }
    cout << answer << endl;
}