#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

bool check(const std::string& ss, const std::string& t){
    for(int i=0; i<t.size(); i++){
        if(ss[i]==t[i]) continue;
        if(ss[i]=='?')  continue;
        return 0;
    }
    return 1;
}

int main(){
    std::string s,t;
    std::cin >> s >> t;

    if(s.size()<t.size()){
        std::cout << "UNRESTORABLE" << "\n";
        return 0;
    }

    std::reverse(s.begin(),s.end());
    std::reverse(t.begin(),t.end());

    bool flag = false;
    for(int i=0; i<s.size()-t.size()+1; i++){
        std::string ss = s.substr(i,t.size());
        if(check(ss,t)){
            s.replace(i,t.size(),t);
            flag = true;
            break;
        }
    }

    if(flag==false){
        std::cout << "UNRESTORABLE" << "\n";
        return 0;
    }

    std::reverse(s.begin(),s.end());
    for(int i=0; i<s.size(); i++){
        if(s[i]=='?') s[i]='a';
    }
    std::cout << s << "\n";
    return 0;
}