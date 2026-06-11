#include <iostream>
using namespace std;
const int MAX_N = 200;
int yakusu[201];
int main(void){
    int N;
    cin >> N;
    for(int i=1;i<=MAX_N;i++){
        for(int j=i;j<=MAX_N;j+=i){
            yakusu[j]++;
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++){
        if(yakusu[i] == 8 && i % 2 == 1){
            ans++;
        }
    }
    cout << ans;
}
