#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    string s;
    cin>>s;
    if(s.length()==2)cout<<s<<endl;
    else{
        rep(i,s.length()){
            cout<<s[s.length()-1-i];
        }
        cout<<endl;
    }
}