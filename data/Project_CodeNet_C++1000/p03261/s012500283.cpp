#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s[n];
    map<string,int>d;
    bool flag=true;
    for(int i=0;i<n;i++){
        cin>>s[i];
        d[s[i]]++;
        if(d[s[i]]>1)flag=false;
        if(i>0){
            if(s[i][0]!=s[i-1][s[i-1].size()-1])flag=false;
        }
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}