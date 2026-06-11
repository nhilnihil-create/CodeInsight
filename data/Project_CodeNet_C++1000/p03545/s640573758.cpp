#include <bits/stdc++.h>
#include <stdio.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    string s;
    cin>>s;
    int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0',d=s[3]-'0';
    if(a+b+c+d==7) printf("%d+%d+%d+%d=7\n",a,b,c,d);
    else if(a-b+c+d==7) printf("%d-%d+%d+%d=7\n",a,b,c,d);
    else if(a+b-c+d==7) printf("%d+%d-%d+%d=7\n",a,b,c,d);
    else if(a-b-c+d==7) printf("%d-%d-%d+%d=7\n",a,b,c,d);
    else if(a+b+c-d==7) printf("%d+%d+%d-%d=7\n",a,b,c,d);
    else if(a-b+c-d==7) printf("%d-%d+%d-%d=7\n",a,b,c,d);
    else if(a+b-c-d==7) printf("%d+%d-%d-%d=7\n",a,b,c,d);
    else if(a-b-c-d==7) printf("%d-%d-%d-%d=7\n",a,b,c,d);
}