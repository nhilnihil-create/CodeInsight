#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn=1005;

int change(char a){
    if(a=='M') return 1;
    else if(a=='A') return 2;
    else if(a=='R') return 3;
    else if(a=='C') return 4;
    else if(a=='H') return 5;
}
long long  a[6]={0};
long long ans;
int main() {
    int n,cnt=0;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s[0]=='M'||s[0]=='A'||s[0]=='R'||s[0]=='C'||s[0]=='H'){
            a[change(s[0])]++;
        }
    }
   ans=a[1]*a[2]*a[3]+a[1]*a[2]*a[4]+a[1]*a[2]*a[5]+a[2]*a[3]*a[4]+a[2]*a[3]*a[5]+a[1]*a[3]*a[4]+a[1]*a[3]*a[5]+a[2]*a[4]*a[5]+a[3]*a[4]*a[5]+a[1]*a[4]*a[5];
   cout<<ans;
   return 0;
}