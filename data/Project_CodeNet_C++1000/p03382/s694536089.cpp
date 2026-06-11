#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100000+10;
int n,a[N];
int dis(int x,int y){
    if(y+y>x) y=x-y;
    return y;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int mx=*max_element(a+1,a+1+n);
    int mn=-1,v=-1;
    for(int i=1;i<=n;i++){
        if(a[i]==mx) continue;
        if(dis(mx,a[i])>mn){
            v=a[i]; mn=dis(mx,a[i]);
        }
    }
    printf("%d %d\n", mx,v);
}