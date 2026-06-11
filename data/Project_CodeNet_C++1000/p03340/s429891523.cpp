
#include<cstdio>
using namespace std;

int n, a[2000010];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int j = 1;
    long long suma = 0, sumb = 0, ret = 0;
    for(int i = 1; i <= n; i++){
        while(j-1 <= n && suma == sumb){
            suma ^= a[j], sumb += a[j];
            j++;
        }
        suma ^= a[j-1], sumb -= a[j-1];
        suma ^= a[i], sumb -= a[i];
        ret += j - i - 1;
        j--;
    }
    printf("%lld\n", ret);
    return 0;
}