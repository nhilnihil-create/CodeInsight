#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    bool f=false;
    f(i,0,s.size()){
        s=s[s.size()-1]+s;
        s.erase(s.size()-1);
        if(s==t){
            f=true;
        }
    }
    if(f){
         cout<<"Yes"<<endl;
     }
     else{
         cout<<"No"<<endl;
     }
    return 0;
}
