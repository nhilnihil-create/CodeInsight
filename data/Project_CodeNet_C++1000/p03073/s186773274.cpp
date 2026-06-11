#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int count=0,count1=0;
    if(s.size()==1)
        cout<<"0"<<endl;
    else
    {
        for(int i=0;i<s.size();i++)
        {
            if((s[i]=='0'&&i%2==0)||(s[i]=='1'&&i%2==1))
            {
                count++;
            }
            else
                count1++;
        }
         cout<<min(count,count1)<<endl;
    }
}
