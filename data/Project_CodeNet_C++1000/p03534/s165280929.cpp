#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char x[100005];
int a[3];
int main(void){
    cin>>x;
    int xl=strlen(x);
    for(int i=0;i<xl;i++)a[int(x[i]-'a')]++;
    sort(a,a+3);
    if((a[0]==a[1]&&a[2]==a[1]+1)||(a[0]+1==a[1]&&a[1]==a[2])||(a[0]==a[1]&&a[1]==a[2]))cout<<"YES\n";
    else cout<<"NO\n";
}
