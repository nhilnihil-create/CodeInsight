#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<long long> s(5);
    cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
    long long minv = 10000;
    do{
        long long order_time = 0;
        long long come_time = 0;
        for(long long i = 0; i < 5; i++){
            come_time = order_time + s[i];
            if(come_time % 10 == 0){
                order_time = come_time;
            }
            else{
                order_time = (come_time/10 + 1) * 10;
            }
        }
        minv = min(minv, come_time);
    }while(next_permutation(s.begin(), s.end()));

    cout << minv << endl;
    return 0;
}