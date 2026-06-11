#include<cstdio>
#include<algorithm>
using namespace std;

int arr[111111];
int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int x = *max_element(arr,arr+n);
    int d = x/2, y = -1;
    for(int i=0;i<n;i++){
        if(abs(d-y) > abs(d-arr[i]) && arr[i] != x)
            y = arr[i];
    }

    printf("%d %d\n", x, y);
}
