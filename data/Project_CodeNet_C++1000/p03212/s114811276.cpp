#include<bits/stdc++.h>
using namespace std;
int ans = 0;
long long n;
void dfs(long long x,bool a, bool b, bool c){
    if(x > n) return;
    if(a && b && c) ans ++;
    dfs(10*x + 3,true,b,c);
    dfs(10*x + 5,a,true,c);
    dfs(10*x + 7,a,b,true);

}

int main(){
    cin >> n;
    dfs(0,false,false,false);
    cout << ans << endl;

}