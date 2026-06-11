#include <iostream>
#include <cstdio>
using namespace std;



int main(){
    string s;
    cin >> s;

    long long count_0 = 0;
    long long count_1 = 0;

    for(long long i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            count_0++;
        }
        else{
            count_1++;
        }
    }

    if(count_0 == 0 || count_1 == 0){
        printf("0\n");
    }
    else{
        printf("%lld\n", 2*min(count_0, count_1));
    }

    return 0;
}