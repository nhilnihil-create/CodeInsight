#include<cstdio>
using namespace std;
const int N = 2 * 1e5 + 10;

int n, a[N];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int j = 1;//右端点
    long long suma = 0, sumb = 0, ret = 0;//suma: XOR  sumb: 和
    for(int i = 1; i <= n; i++){//枚举左端点
        while(j-1 <= n && suma == sumb){//滑动右端点
            suma ^= a[j], sumb += a[j];//一波操作666？？
            j++;//右端点往右移
        }
        ret += j - i - 1;
        //跳出循环是因为j位置的2个数不符合条件，所以将这2个位置从suma和sumb中剔除
        suma ^= a[j-1], sumb -= a[j-1];
        //左端点会往右移，所以将最左边的2个位置从suma和sumb中剔除
        suma ^= a[i], sumb -= a[i];
        //跳出循环是因为j位置的2个数不符合条件，所以j-1是满足条件的最右位置
        j--;
    }
    printf("%lld\n", ret);
    return 0;
}