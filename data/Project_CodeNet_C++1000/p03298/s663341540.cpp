// NOT MY CODE
#include <map>
#include <iostream>
using namespace std;
typedef pair<string,string> pa;
int main() {
    int n;
    long long ans = 0;
    string s;
    map<pa,int> mp;
    cin>>n>>s;
    for(int i = 0;i < 1 << n;i ++) {
        string a = "";
        string b = "";
        for(int j = 0;j < n;j ++) {
            if(i >> j & 1)a += s[j];///二进制位为1 属于a串
            else b += s[j];///二进制位为0 属于ra串
        }
        mp[pa(a,b)] ++;///记录状态个数
    }
    for(int i = 0;i < 1 << n;i ++) {
        string a = "";
        string b = "";
        for(int j = 0;j < n;j ++) {
            if(i >> j & 1)a += s[n * 2 - 1 - j];///二进制位为1 属于a串
            else b += s[n * 2 - 1 - j];///二进制位为0 属于ra串
        }
        ans += mp[pa(a,b)];///加上匹配的状态个数
    }
    cout<<ans;
}