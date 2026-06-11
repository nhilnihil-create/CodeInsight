#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool no=false;
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='a'+i){
            no=true;
            break;
        }
    }
    if(no)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
}