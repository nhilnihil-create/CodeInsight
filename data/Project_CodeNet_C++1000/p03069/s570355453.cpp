#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main(){
    long long n;
    string s;

    cin >> n;
    cin >> s;

    vector<long long> white_sum(n+1, 0);
    vector<long long> black_sum(n+1, 0);

    for(long long i = 0; i < n; i++){
        if(s[i] == '.'){
            white_sum[i+1] = white_sum[i] + 1;
        }
        else{
            white_sum[i+1] = white_sum[i];
        }

        if(s[i] == '#'){
            black_sum[i+1] = black_sum[i] + 1;
        }
        else{
            black_sum[i+1] = black_sum[i];
        }
    }

    long long minv = 1e9;
    for(long long left = 0; left <= n; left++){
        long long tmp = 0;
        tmp += black_sum[left] - black_sum[0];
        tmp += white_sum[n] - white_sum[left];

        minv = min(minv, tmp);
    }
    cout << minv << endl;
    return 0;
}