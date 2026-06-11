#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    int i = n / 111; //111の何倍か
    if(n % 111 != 0) i++; //割り切れなかったら次の倍数にする

    printf("%d", i * 111); 
    return 0;
}