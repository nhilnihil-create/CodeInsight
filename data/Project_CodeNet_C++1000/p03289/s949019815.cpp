#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     ll t,cnt=0,pk;
     string str;
     cin>>str;
     if(str[0]=='A')
     {
         pk=str.size();
         for(int i=1;i<pk;i++)
         {
             if(i>=2 && i<pk-1)
             {
                 if(str[i]=='C')
                    cnt++;
                 else if(str[i]<'a' || str[i]>'z')
                 {
                     cout<<"WA"<<endl;
                     return 0;
                 }
                 else
                    continue;
             }
             else if(str[i]<'a' || str[i]>'z')
                 {
                     cout<<"WA"<<endl;
                     return 0;
                 }
            else continue;
         }
         if(cnt==1)
            cout<<"AC"<<endl;
         else
            cout<<"WA"<<endl;
     }
     else
        cout<<"WA"<<endl;
}
