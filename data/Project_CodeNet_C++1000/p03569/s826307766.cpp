#include <bits/stdc++.h>    //万能头文件
using namespace std;
string  st;
int ans;        //记录次数
bool    flag = true;    //用来标记是否能构造回文
int main()
{
    cin >> st;
    int L=0,R = st.size() - 1;  //定义左、右端
    while ( L <= R )    //运行到字符串中间
    {
        if ( st[L] == st[R] ) {L++,R--;continue;}
        if ( st[L] == 'x' ) {L++,ans++;continue;}
        if ( st[R] == 'x' ) {R--,ans++;continue;}
        flag = false; break;
    }
    ans = flag ? ans : -1;  
    cout << ans;
    return 0;
}