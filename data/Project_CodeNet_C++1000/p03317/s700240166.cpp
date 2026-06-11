#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int N,K;
    int number;
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        int a;
        cin >> a;
        if(a == 1){
            number = i;
        }
    }
    int ans = 0;
    int l,r;
    l = r = number;
    while(l > 1){
        
        l = l - K + 1;
        ans++;
    }
    if(l <= 0){
        r = r - l + 1;
    }
    while(r < N){
        r = r + K - 1;
        ans++;
    }
    

    cout << ans << endl;
}
