#include <cstdio>
#include <cstring>
char a[4];int res=700;
int main()
{
    scanf("%s",a); // 注意这里不需要 &a
    for (register int i=0;i<strlen(a);++i)
        if (a[i]=='o')
            res += 100; // 判断 'o' 
    printf("%d\n",res); // 输出结果，记得要换行
    return 0;
}