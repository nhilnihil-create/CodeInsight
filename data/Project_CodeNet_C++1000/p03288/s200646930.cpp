#include<bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
vector<string>v;
void dfs(string str,string t="",int cnt=0){
    if(cnt==2){
        v.push_back(t);
        return;
    }else{
        for(int i=0;i<str.size();i++){
            dfs(str,t+str[i],cnt+1);
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    while(cin>>n){
        if(n>=2800)cout<<"AGC"<<endl;
        else if(n>=1200)cout<<"ARC"<<endl;
        else cout<<"ABC"<<endl;
    }
    return 0;
}
