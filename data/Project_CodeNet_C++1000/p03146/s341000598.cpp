#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(){
    long long s;
    cin >> s;

    vector<long long> a(1000001);
    a[0] = s;

    for(long long i = 1; i <= 1000000; i++){
        if(a[i-1] % 2 == 0) a[i] = a[i-1]/2;
        else a[i] = 3*a[i-1]+1;
    }

    set<long long> T;

    for(long long i = 0; i <= 1000000; i++){
        if(T.find(a[i]) == T.end()) T.insert(a[i]);
        else{
            printf("%lld\n", i+1);
            return 0;
        }
    }
    return 0;
}