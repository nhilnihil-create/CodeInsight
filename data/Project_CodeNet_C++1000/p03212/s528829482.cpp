#include<iostream>
#define ll long long

bool check(std::string s){
    bool three=false,five=false,seven=false;
    for(char c : s){
        if(c == '3') three=true;
        if(c == '5') five=true;
        if(c == '7') seven=true;
    }
    return three && five && seven;
}
ll dfs(std::string s, int n){
    if(std::stol(s) > n) return 0;
    ll ans=0;
    if(check(s)) ++ans;
    std::string ss[] = {"3","5","7"};
    for(auto c : ss){
        auto t = s+c;
        ans += dfs(t,n);
    }
    return ans;
}

int main(){
    ll n; std::cin >> n;
    ll ans=dfs("0",n);
    std::cout << ans << std::endl;

    return 0;
}