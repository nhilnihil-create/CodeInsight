#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long x, y;
    cin >> x >> y;

    vector<long long> a;

    a.push_back(x);
    
    long long i = 0;
    long long b = 0;
    while(1){
        b = 2*a[i];
        
        if(b <= y){
            a.push_back(b);
            i++;
        }
        else{
            break;
        }
    }

    printf("%lld\n", i+1);

    return 0;

}