#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
char a[10][10];
int main() {
double X;
cin>>X;
double ans=1;
for(int b=1;b<=1000;b++){
    for(int p=2;p<=1000;p++){
        if(pow(b,p)<=X){ans=max(ans,pow(b,p));}
    }
}
cout<<ans<<endl;
 return 0;}