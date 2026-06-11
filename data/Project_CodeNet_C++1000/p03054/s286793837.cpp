#include<bits/stdc++.h>
using namespace std;
char a[3][101010 * 2];

bool deal(char x, char y, int cnt, const int maxv){
    for(int i = 1; a[1][i]; i ++){
        if(a[1][i] == x) cnt --;
        if(cnt == 0) return true;
        if(a[2][i] == y) cnt ++;
        cnt = min(maxv, cnt);
    }
    return false;
}
int main(){
    int h, w, n, x, y;
    scanf("%d%d%d%d%d", &h, &w, &n, &x, &y);
    scanf("%s%s", a[1] + 1, a[2] + 1);
    bool flag = false;
    flag = flag | deal('R', 'L', w - y + 1, w);
    flag = flag | deal('L', 'R', y, w);
    flag = flag | deal('U', 'D', x, h);
    flag = flag | deal('D', 'U', h - x + 1, h);
    printf("%s\n", flag ? "NO" : "YES");
}