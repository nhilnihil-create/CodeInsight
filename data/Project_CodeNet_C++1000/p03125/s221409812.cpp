#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,n) for(int i=1; i<=(n); i++)

int main() {
    int a,p,ans;
    cin>>a>>p;
    if(p%a==0)ans=a+p;
    else ans=p-a;
    cout<<ans;
    return 0;
}

