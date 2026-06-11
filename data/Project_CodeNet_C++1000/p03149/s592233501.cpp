#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int a[4];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    
    // 2. sort.
    sort(a, a + 4);
    
    // 3. 出力.
    if(a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) puts("YES");
    else                                                 puts("NO");
    return 0;
    
}