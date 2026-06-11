#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    int f=0,b=0;
    if(s[0]=='0'&&s[1]!='0'){
        f=1;
    }
    else if(s[0]=='1'&&(s[1]=='0'||s[1]=='1'||s[1]=='2')){
        f=1;
    }
    if(s[2]=='0'&&s[3]!='0'){
        b=1;
    }
    else if(s[2]=='1'&&(s[3]=='0'||s[2]=='1'||s[3]=='2')){
        b=1;
    }

    if(f==1&&b==1){
        cout<<"AMBIGUOUS"<<endl;
    }
    else if(f==1){
        cout<<"MMYY"<<endl;
    }
    else if(b==1){
        cout<<"YYMM"<<endl;
    }
    else{
        cout<<"NA"<<endl;
    }


    return 0;
}
