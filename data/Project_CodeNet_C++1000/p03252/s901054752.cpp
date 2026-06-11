#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    string s,t,n,ans;
    int a=-1;
    cin>>s>>t;
    n="abcdefghijklmnopqrstuvwxyz";
    ans="Yes";
    for(int i=0;i<26;i++){
        for(int j=0;j<s.size();j++){
            if(s[j]==n[i]){
                if(a==-1){
                    a=j;
                }
                else{
                    if(t[j]!=t[a]){
                        ans="No";
                        break;
                    }
                    else{
                        a=j;
                    }
                }
            }
        }
        if(ans=="No"){
            break;
        }
        a=-1;
    }
    for(int i=0;i<26;i++){
        if(ans=="No"){
            break;
        }
        for(int j=0;j<t.size();j++){
            if(t[j]==n[i]){
                if(a==-1){
                    a=j;
                }
                else{
                    if(s[j]!=s[a]){
                        ans="No";
                        break;
                    }
                    else{
                        a=j;
                    }
                }
            }
        }
        if(ans=="No"){
            break;
        }
        a=-1;
    }
    cout<<ans<<endl;
    return 0;
}
