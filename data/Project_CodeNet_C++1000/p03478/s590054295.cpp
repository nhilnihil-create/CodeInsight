#include<iostream>
#include<algorithm>
#include<cmath>
#define rep(i, n) for(i=1; i<=n; i++)
using namespace std;
int sod(int a)
{
    int sum = 0;
    while(a>0){
        sum += a%10;
        a = a/10;
    }
    return sum;
}
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int i, count = 0;
    //int sum = 0;
    rep(i, n){
      if(sod(i)>=a && sod(i)<=b) count += i;  
    }
    cout << count << endl;
    return 0;
}