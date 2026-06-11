#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    map<int,int> mp_s;
    map<int,int> mp_p;
    int s_num;
    int t_num;
    int flag=0;
    for(int i=0;i<s.length();i++){
        s_num=s[i]-'a'+1;
        t_num=t[i]-'a'+1;
        if(mp_s[s_num]==0)mp_s[s_num]=t_num;
        else if(mp_s[s_num]!=t_num)flag++;
        if(mp_p[t_num]==0)mp_p[t_num]=s_num;
        else if(mp_p[t_num]!=s_num)flag++;
        if(flag>0)break;
    }
    if(flag>0)cout << "No" << endl;
    else cout << "Yes" << endl;
}