#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mxn= 5e5+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    string s;
    cin>>s;
    bool f=true;
    int ans1=0,ans2=0,n=s.size();
    for(int i=0;i<n;i++){
        if(f==true&&s[i]=='1'){
            ans1++;
        }
        else if(f==false&&s[i]=='0'){
            ans1++;
        }
        f=!f;
    }
    f=false;
    for(int i=0;i<n;i++){
        if(f==true&&s[i]=='1'){
            ans2++;
        }
        if(f==false&&s[i]=='0'){
            ans2++;
        }
        f=!f;
    }
    cout<<n-max(ans1,ans2);
}

