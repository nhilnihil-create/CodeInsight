#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    int a,b,max;
    cin >> a >> b;
    max = (a+b);
    if(a-b > max) max = (a-b);
    if(a*b > max) max = (a*b);
    
    cout << max << endl;
    return 0;
}
