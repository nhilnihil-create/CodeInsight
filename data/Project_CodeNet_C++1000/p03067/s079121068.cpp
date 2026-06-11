#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)swap(a,b);
    if(a<c&&c<b)puts("Yes");
    else puts("No");
    return 0;
}