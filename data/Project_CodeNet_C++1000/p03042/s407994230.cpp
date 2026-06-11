#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<string>v ={"01","02","03","04","05","06","07","08","09","10","11","12"};
    string yymm,mmyy;
    yymm+=s[2];
    yymm+=s[3];
    mmyy+=s[0];
    mmyy+=s[1];
    int cnt=0,cnt1=0;
    if(find(v.begin(),v.end(),yymm)!=v.end())
        cnt++;
    if(find(v.begin(),v.end(),mmyy)!=v.end())
        cnt1++;
    if(cnt==1&&cnt1==1)
        cout<<"AMBIGUOUS"<<endl;
    else if(cnt==1)
        cout<<"YYMM"<<endl;
    else if(cnt1==1)
        cout<<"MMYY"<<endl;
    else
        cout<<"NA"<<endl;

}
