#include<cstdio>
#include<iostream>

std::string getS(std::string s,int l,int r){
    std::string res = ""; 
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(i>=l && i<=r) continue;
        else res.push_back(s[i]);
    }
    return res;
}

int main(){
    std::string s;
    std::cin>>s;
    std::string t = "keyence";
    if(s==t) printf("YES\n");
    else{
        int n = s.size();
        int ok = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                std::string cur = getS(s,i,j);
                if(cur==t) ok = 1;
            }
        } 
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
