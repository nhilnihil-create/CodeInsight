#include<iostream>
#include<string>

using namespace std;
typedef long long LL;
int arr[100],ans[100];
int main(){
    LL a,b;
    LL ans = 0;
    cin >> a >> b;
    for(LL i= a+4-a%4 -1;i>=a ;i--) 
        ans = ans^i;
    for(LL j=b-b%4 ;j<=b;j++) 
        ans = ans^j;
    cout<<ans<<endl;
    return 0;
}