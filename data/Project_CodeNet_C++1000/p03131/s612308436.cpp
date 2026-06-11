#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int k,a,b,sum=0;
    cin>>k>>a>>b;
    long long int tmp=k+1;
    if (a<b) {
        if (k-(a-1)>=0) {
            k-=a-1;
            if (k>=2) {
                sum+=a+((b-a)*(k/2));
                if (k%2!=0) {
                    sum+=k%2;
                }
            } else {
                sum+=k;
            }
        } else {
            sum+=k+1;
        }
    } else {
        sum+=k+1;
    }
    cout<<max(sum,tmp)<<endl;
}