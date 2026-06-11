#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    LL Y;
    cin >> N >> Y;

    int count_max_man = min({Y/10000, (LL)N});

    for(int i=count_max_man; i>=0; i--){
        for(int j=N-i; j>=0; j--){
            int k = N - i - j;
            if(k < 0)continue;

            if(10000*i + 5000*j + 1000*k == Y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }

    }

    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}