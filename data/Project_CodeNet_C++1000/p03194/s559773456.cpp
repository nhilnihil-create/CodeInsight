#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define int long long
int prime[1000000];
int divide[1000000];
signed main(){
    int n, p;
    cin >> n >> p;
    int index = 0;
    int tmp = p;
    for(int i=2; i * i <= tmp; ++i){
        if(p % i) continue;
        prime[index] = i;
        while(p % i == 0){
           divide[index]++; 
           p /= i;
        }
        index++;
    }
    //for(int i=0; i<index; ++i) cout << prime[i] << endl;
    //for(int i=0; i<index; ++i) cout << divide[i] << endl;
    prime[index] = p;
    divide[index] = 1;
    index++;

    int res=1;
    for(int i=0; i<index; ++i){
        //cout << divide[i] << " " << n << " " << divide[i]/n << endl;
    
        while(divide[i]>=n){
            res *= prime[i];
            divide[i] -= n;
        }
    }
    cout << res << endl;
    return 0;
}