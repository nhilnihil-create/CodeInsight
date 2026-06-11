#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
 
int main(){
    long long N,P;
    long long ans = 1;

    cin >> N >> P;

    if(N == 1){
        cout << P << endl;
        return 0;
    }

    for(long long i = 2;i <= 1000000;i++){
        long long n = P;
        int cnt = 0;

        while(n % i == 0){
            cnt++;
            n /= i;
        }

        if(cnt >= N)ans = i;
    }

    cout << ans << endl;

    return 0;
}