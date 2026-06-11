#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt[3] = {0};
    for(int i=0;i<s.size();++i){
        cnt[s[i]-'a']++;
    }

    sort(cnt, cnt+3);

    int a[3]={0};
    for(int i=0;i<s.size();++i){
        a[2-i%3]++;
    }

    bool flag = true;
    for(int i=0;i<3;++i){
        if(cnt[i] != a[i]){
            flag = false;
            break;
        }
    }

    if(flag)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
