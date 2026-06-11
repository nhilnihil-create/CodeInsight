#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;

    long long minv = a;
    minv = min(minv, b);
    minv = min(minv, c);
    minv = min(minv, d);
    minv = min(minv, e);

    
    long long team;

    if(n <= minv){
        printf("5\n");
    }
    else{
        team = (n+ minv -1 )/minv;
        printf("%lld\n", 4 + team);
    }
    

    

    return 0;
}