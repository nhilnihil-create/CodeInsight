#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[101010];
int main(){
    scanf("%d",&n);
    int mx = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        mx = max(mx, a[i]);
    }
    int diff = 1000000001;
    int x;
    for(int i=0;i<n;i++){
        int d = abs(a[i]*2-mx);
        if (diff > d && a[i] != mx){
            x = a[i];
            diff = d;
        }
    }
    printf("%d %d\n", mx, x);
}
