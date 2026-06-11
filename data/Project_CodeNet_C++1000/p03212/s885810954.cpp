#include<bits/stdc++.h>
#define ll long long
using namespace std ; 

bool check(string s){//文字列の中に3,5,7が全て含まれているか？
    bool three=false,five=false,seven=false;
    for(char c : s){
        if(c == '3') three=true;
        if(c == '5') five=true;
        if(c == '7') seven=true;
    }
    return three && five && seven;//含まれて入ればtrue
}

ll dfs(string s, int n){
    if(stoll(s) > n) return 0;
  
    ll ans=0;
    if(check(s)) ans++ ;//checkでtrueが返ってくるとans = ans+1
  
  
    string ss[] = {"3","5","7"};
    for(auto c : ss){
        auto t = s+c;
        ans += dfs(t,n);
    }
  
  
    return ans;
}

int main(){
    ll n; cin >> n;
    ll ans=dfs("0",n);
    cout << ans << endl;

    return 0;
}