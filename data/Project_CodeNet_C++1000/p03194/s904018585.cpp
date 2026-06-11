#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
    long long n,p,count=0,a=1,hozon;
    cin >> n >> p;
    hozon = p;
    if(n>=2){
    for(int i=2;i<=sqrt(p);i++){
        while(p%i==0) {count++;p=p/i;}
        if(count>=n) {a=i;}
        count = 0;
        p = hozon;
    }
        cout << a;
    }
    if(n==1) cout << p;

}