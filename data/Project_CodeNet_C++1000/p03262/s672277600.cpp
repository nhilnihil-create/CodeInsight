#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int GCD(int a,int b){
    if(b == 0)return a;
    return GCD(b,a%b);
}
int main(void){
    int N,X;
    cin >> N >>X;
    int x[N];
    for(int i=0;i<N;i++){
        cin >> x[i];
        x[i] = abs(X-x[i]);
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        ans = GCD(ans,x[i]);
    }
    cout << ans;
}
