#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int main(){
    string s;cin>>s;
    int a=(s[0]-'0')*10+s[1]-'0';
    int b=(s[2]-'0')*10+s[3]-'0';
    if(a<=12&&b<=12&&a>0&&b>0){
        cout<<"AMBIGUOUS"<<endl;
    }
    else if(a<=12&&a>0){
        cout<<"MMYY"<<endl;
    }
    else if(b<=12&&b>0){
        cout<<"YYMM"<<endl;
    }
    else{
        cout<<"NA"<<endl;
    }
}
