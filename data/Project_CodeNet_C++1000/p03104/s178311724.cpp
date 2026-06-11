#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long A, B;
    cin >> A >> B;
    vector<long long> usea(40, 0), useb(40, 0);
    long long t = 1;
    long long ans = 0;
    long long cnt = 0;
    while(B >= t){
        long long syo = B / (t * 2);
        long long m = B % (t * 2);
        if(m >= t - 1) m -= t - 1;
        else m = 0;
        useb[cnt] += syo * t + m;
        t *= 2;
        cnt++;
    }
    t = 1;
    cnt = 0;
    A--;
    while(A >= t){
        long long syo = A / (t * 2);
        long long m = A % (t * 2);
        if(m >= t - 1) m -= t - 1;
        else m = 0;
        usea[cnt] += syo * t + m;
        t *= 2;
        cnt++;
    }
    for(int i = 0; i < 40; i++){
        if((useb[i] - usea[i]) % 2 == 1) ans += (1LL << i);
    }
    cout << ans << endl;
}