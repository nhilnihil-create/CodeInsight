#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100100];

int main() {
    int i;
    
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int mini = 2e9, t = 0;
    for (i=0;i<n-1;i++) {
        if (mini>abs(arr[n-1]-2*arr[i])) {
            mini=abs(arr[n-1]-2*arr[i]);
            t=arr[i];
        }
    }
    printf("%d %d\n",arr[n-1],t);
    
    return 0;
}
