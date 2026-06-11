#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;


int main(void){
    int N;
    cin >> N;
    vector<int> a(101, 0);
    int tmp;
    for(int i = 1 ; i <= N; i++){
        tmp = i;
        for(int j = 2; j * j <= tmp; j++){
            while(tmp % j == 0){
                a.at(j)++;
                tmp = tmp / j;
            }
        }
        if(tmp != 1) a.at(tmp)++;
    }
    
    int ans = 0;
    //74
    for(int i = 2; i <= 100; i++){
        if(a.at(i) >= 74) ans++;
    }
    //4+14
    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            if(i == j) continue;
            if(a.at(i) >= 4 && a.at(j) >= 14) ans++;
        }
    }
    //2+24
    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            if(i == j) continue;
            if(a.at(i) >= 2 && a.at(j) >= 24) ans++;
        }
    }
    int tmpans = 0;
    //2+4+4
    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            if(i == j) continue;
            for(int k = 2; k <= 100; k++){
                if(k == j) continue;
                if(i == k) continue;
                if(a.at(i) >= 2 && a.at(j) >= 4 && a.at(k) >= 4) tmpans++;
            }
        }
    }
    ans += tmpans/2;
    printf("%d\n", ans);
}

