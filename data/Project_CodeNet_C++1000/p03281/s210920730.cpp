#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;


int main(void){
    ll n;
    cin>>n;
    vector <ll> a(n+1);
    for(int i=1;i<=n+1;i++){
        for(int j=i;j<=n;j+=i){
            a[j]++;
        }
    }
    
    ll c=0;
    for(int i=1;i<=n;i+=2){
        if(a[i]==8)c++;
    }
    cout<<c<<endl;
}
