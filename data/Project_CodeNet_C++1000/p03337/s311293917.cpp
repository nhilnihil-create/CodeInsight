#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int ans;
    ans=max(a+b,max(a-b,a*b));
    cout<<ans<<endl;
    return 0;
}