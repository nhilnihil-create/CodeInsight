#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e5+7;
int n;
int a[N];
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans+=a[i]-1;
    }
    printf("%d\n",ans);
}
