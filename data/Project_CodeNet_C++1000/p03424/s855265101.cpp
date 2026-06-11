#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    char s[n];
    for(long long i = 0; i< n; i++) cin >> s[i];

    for(long long i = 0; i < n; i++){
        if(s[i] == 'Y'){
            printf("Four\n");
            return 0;
        }
    }
    printf("Three\n");
    return 0;
}