#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
#define INF 1000000007
using namespace std;

int main(void){
    long long n,p,temp,ans=1;
    int count=0;
    cin >> n >> p;
    if(n>=40){
        cout << 1 << endl;
        return 0;
    }
    if(n==1){
        cout << p << endl;
        return 0;
    }
    for(long long i=2; i<=p; i++){
        temp=1;
        for(int j=0; j<n; j++)temp*=i;
        while(p%temp==0){
            ans*=i;
            p/=temp;
        }
        while(p%i==0)p/=i;
        if(temp>=p)break;
    }
    cout << ans << endl;
    return 0;
}
