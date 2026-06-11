#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

typedef long long LL;

LL k;

bool check(LL n){
    LL m = n;
    int c[20], tot = 0;
    int digitsum = 0;
    while(n > 0){
        c[++tot] = n % 10;
        n /= 10;
        digitsum += c[tot];
    }
    //reverse(c + 1, c + 1 + tot);
    LL now = 1;
    for(int i = 1;i <= tot;i++){
        if(c[i] != 9){
            break;     
        }
        now *= 10;
    }
    if(now * digitsum >= m)
        return true;
    else
        return false;
}

LL power[15];


int main(){
    cin >> k;
    power[0] = 1;
    for(int i = 1;i <= 15;i++){
        power[i] = power[i - 1] * 10;
    } 
    vector<LL> ans;
    for(int i = 1;i < 10000;i++){
        if(check(i)){
            ans.push_back(i);
            //cout << i << endl;
        }
    } 
    for(int i = 5;i <= 15;i++){
        for(int j = 100;j < 1000;j++){
            LL tmp = j * power[i - 3] + (power[i - 3] - 1);
            if(check(tmp)){
                //cout << tmp << endl;
                ans.push_back(tmp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0;i < k;i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}
