#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int a[3];
    int ans=0;
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    sort(a,3+a);
    ans = a[2]-a[1];
    ans = ans+a[1]-a[0];
    printf("%d\n",ans);
    return 0;
}