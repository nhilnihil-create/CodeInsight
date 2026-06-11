#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    for(int i=0;i<a;i++){
        if(s[i]>='0'&&s[i]<='9')continue;
        else{
            cout<<"No";
            return 0;
        }
    }
    if(s[a]!='-'){
            cout<<"No";
            return 0;
    }
    for(int i=a+1;i<a+b+1;i++){
        if(s[i]>='0'&&s[i]<='9')continue;
        else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}

