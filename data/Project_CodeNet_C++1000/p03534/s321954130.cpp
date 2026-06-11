#include<bits/stdc++.h>
using namespace std;
string s;
int num[3];
int main(){
    while(cin>>s){
        memset(num,0,sizeof(num));
        for(int i=0;s[i];++i)
            ++num[s[i]-'a'];
        int len=s.length();
        int a=0;
        for(int i=0;i<3;++i) a+=num[i]!=0;
        sort(num,num+3);
        if(a==1) {
            if(len==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(a==2){
            if(num[2]==1 && num[1]==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else if(a==3){
            if(num[2]==num[1]+1 && num[1]==num[0]+1) cout<<"NO"<<endl;
            else if(num[2]<=num[1]+1 && num[1]<=num[0]+1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
