#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int su[100001];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&su[i]);
        su[i] *= 2;
    }
    sort(su, su+n, greater<int>());
    int target = su[0]/2;
    int mn = su[0]+2, mnn = -1;
    for(int i=1;i<n;i++){
        if(-mn < su[i]-target && su[i]-target < mn){
            mnn = i;
            mn = su[i]-target;
            if(mn < 0) mn = -mn;
        }
    }
    printf("%d %d\n", su[0]/2, su[mnn]/2);
}