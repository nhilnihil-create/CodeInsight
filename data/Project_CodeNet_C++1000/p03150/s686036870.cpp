#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
    string s;
    cin>>s;

    bool ok = false;
    int len = s.length();
    string k;

    for(int i=0;i<7;i++){
        string k;
        for(int j=0;j<i;j++) k += s[j];
        for(int j=0;j<7-i;j++) k += s[len-7+i+j];
        if(k == "keyence") ok = true;
    }

    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}