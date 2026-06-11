#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define ll long long
int main()
{
    int n,k;
    ll cnt = 0;
    cin>>n>>k;
    for(int i=k+1;i<=n;i++){
        cnt += 1ll*(i-k)*(n/i);
        cnt += 1ll*max(0 , n%i - k + 1);
    }
    if(k == 0){
        cnt -= n;
    }
    cout<<cnt<<endl;

    return 0;
}
