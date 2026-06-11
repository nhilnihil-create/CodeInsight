#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int collatz(int x){
    if(x % 2 == 0){
        return x / 2;
    }
    else{
        return x * 3 + 1;
    }
}
int main(void){
    int N;
    cin >> N;
    int h[N];
    for(int i=0;i<N;i++)cin>>h[i];
    
    bool OK = false;
    int ans = 0;
    while(!OK){
        OK = true;
        for(int i=0;i<N;i++){
            if(h[i] > 0){
                for(int j=i;j<N;j++){
                    if(h[j] > 0)h[j]--;
                    else break;
                }
                OK = false;
                ans ++;
                break;
            }
        }
    }
    
    cout << ans << endl;
}
