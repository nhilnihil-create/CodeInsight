#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    string s;
    cin>>s;
    int num;
    int min=999;
    for(int i=0;i<s.size()-2;i++){
        num = (int)(s[i]-'0')*100 + (int)(s[i+1]-'0')*10 + (int)(s[i+2]-'0');
        // cout<<num<<endl;
        min=std::min(min,abs(753-num));
    }
    cout<<min<<endl;   
}

