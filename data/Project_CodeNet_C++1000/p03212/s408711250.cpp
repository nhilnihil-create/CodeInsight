#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
int flag[10] = {0};
string s;
int ans = 0;

bool check(){
    bool ret = true;
    rep(i, 3)   if(!flag[3+i*2]) ret = false;
    return ret;
}

void dfs(){
    if(s.size() != 0){
        if(stol(s) > n) return;
    }
    if(check()) ans++;
    for(int i = 3; i <= 7; i+=2){
        s += to_string(i);
        flag[i]++;
        dfs();
        flag[i]--;
        s.pop_back();
    }
}

int main(){
    cin>>n;
    dfs();
    cout<<ans<<endl;
}
