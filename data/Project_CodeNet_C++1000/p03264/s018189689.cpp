#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    int k;
    cin>>k;
    int odd = 0,eve = 0;
    rep(i,1,k){
        if(i % 2 == 0) eve++;
        else odd++;
    }
    cout<<odd * eve<<endl;
    return 0;
}