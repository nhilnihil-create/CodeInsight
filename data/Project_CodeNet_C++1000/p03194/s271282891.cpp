#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;
long long ans = 1;
int main(void){
    long long N,P;
    cin >> N >> P;
    if(N==1){
        cout << P << endl;
        return 0;
    }
    for(long long i=2;i * i<=P;i++){
        if(P % i == 0){
            int count = 0;
            while(P % i == 0){
                P /= i;
                count++;
                if(count == N){
                    ans *= i;
                    count = 0;
                }
            }
        }
    }
    cout << ans;
}
