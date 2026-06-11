#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const ll maxn=1e14;
double eps=1e-6;
static int a[20];
ll n;
ll sum=0;
int main(){
    cin>>n;
    for(ll i=1; i<=sqrt(n)+sqrt(sqrt(n)); i++){
        if(n%i==0 && n/i-1>i){
            sum+=n/i-1;
        }
    }

    cout<<sum;
    return 0;
}
