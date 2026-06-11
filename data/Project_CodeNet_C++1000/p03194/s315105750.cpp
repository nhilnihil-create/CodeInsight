#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main(){
    long long int n, p;
    long long int ans;
    cin >> n >> p;

    if(n == 1){
        ans = p;
    }else if(p == 1){
        ans = 1;
    }else if(n >= 40){
        ans = 1;
    }else if(n >= 26){
        if(pow(2, n) <= p){
            if(p%(long long int)pow(2, n) == 0){
                ans = 2;
            }else{
                ans = 1;
            }
        }else{
            ans = 1;
        }
    }else{
        for(int i = 1; ; i++){
            if(pow(i, n) > p){
                break;
            }else{
                if(p%(long long int)pow(i, n) == 0){
                    ans = i;
                }
            }
        }
    }
    cout << ans << endl;
}
