#include<iostream>
using namespace std;
int len, cnt, cnt1;
string s;
int main() {
    cin>>s;
    len=s.size();
    for (int i = 0; i <len; ++ i)
        if (s[i] == '0')++cnt;
        else if (s[i] == '1')++cnt1;
    cout<<2*min(cnt,cnt1)<<endl;;
    return 0;
}