#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int cnt=0;

void dfs(ll i, int a, int b, int c){
    if(i>n) return;
    if(a>0 && b >0 && c>0) cnt++;
    /*
    string s;
    s = to_string(i);
    set<char> k;
    for(int i=0; i<s.size(); i++){
        k.insert(s.at(i));
    }
    if(k.count('3') && k.count('5') && k.count('7')) cnt++;
    */
    dfs(10*i+3, a+1, b, c);
    dfs(10*i+5, a, b+1, c);
    dfs(10*i+7, a, b, c+1);
}

int main(){
    cin >> n;
    dfs(0, 0, 0, 0);
    cout << cnt << endl;
}