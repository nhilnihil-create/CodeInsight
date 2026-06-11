#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

int main(){
    long long x;
    cin >> x;

    set<long long> T;

    for(long long i = 1; i <= 100; i++){
        for(long long j = 2; j <= 10; j++){
            long long a = (long long)pow(i, j);
            if(a <= x){
                T.insert(a);
            }
        }
    }

    set<long long>::iterator it;
    it = T.end();
    it--;
    cout << *it << endl;

    return 0;
}