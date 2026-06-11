																														#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count1=0,count0=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1'){
            count1++;
        }
        else
        {
            count0++;
        }
    }
    cout<<2*min(count1,count0);
}