#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;

    long long count_w = 0;

    long long sum = 0;

    for(long long i = 0; i < s.size(); i++){
        if(s[i] == 'W'){
            sum += abs(count_w - i);
            count_w++;
        }
    }

    printf("%lld\n", sum);

    return 0;
}