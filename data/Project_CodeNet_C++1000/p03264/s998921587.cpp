#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    int n;
    cin>>n;

    int odd,even;
    if(n%2==0)even=n/2, odd=n/2;
    else even=n/2, odd=n/2+1;

    cout<<even*odd<<endl;

    return 0;
}
