#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int sum=0;
    if (b>=c) {
        sum+=b+c;
    } else {
        sum+=b+b;
        c-=b;
        if (a>=c) {
            sum+=c;
        } else {
            sum+=a+1;
        }
    }
    cout<<sum<<endl;
}