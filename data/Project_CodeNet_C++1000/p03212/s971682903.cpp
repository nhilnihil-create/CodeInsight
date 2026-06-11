#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;
#define int long long
int ans = 0;
int N;

bool check(string s){
    map<char,int> mp;
    for(int i = 0; i < s.size();i++){
        mp[s[i]] += 1;
    }

    if(mp.size() < 3){
        return false;
    }else{
        return true;
    }
}
void recursion(string s){
    if(s == ""){
        recursion(s+"3");
        recursion(s+"5");
        recursion(s+"7");
        return;
    }

    int x = std::stoll(s);
    if(x > N){
        return;
    }else{
        if(check(s)) ans += 1;
        recursion(s+"3");
        recursion(s+"5");
        recursion(s+"7");
    }
}
signed main(){
    cin >> N;
    recursion("");

    cout << ans << endl;
}