#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    int ans = 1e9;
    int len = s.length();
    for (int i = 0; i <= len-2; i++){
        if(s[i]!=s[i+1]){
            ans = min(ans, max(i + 1, len -1 - i));
        }
    }
    //易错!!!如果ans还是1e9的话,答案应该是s.length()!!!我只想着"因为要去最小值所以一开始要初始化一个很大的值"了...
    //其实一开始给ans初始化s.length()就行啦~~
    if(ans==(int)1e9){
        ans = len;
    }
    cout << ans << endl;
    return 0;
}