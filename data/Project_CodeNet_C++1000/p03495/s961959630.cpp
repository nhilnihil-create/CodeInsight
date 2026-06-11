#include <iostream>
#include<map>
#include<queue>
using namespace std;
int main() {
 
       int n,k;
       cin>>n>>k;
       map<int,int> mp;
       priority_queue<int> q;
       for(int i=0;i<n;i++)
       {
           int a;
           cin>>a;
           mp[a]++;
       }
       for(auto it=mp.begin();it!=mp.end();it++)
       {
           q.push(it->second);
       }
       while(k--)
       {
           if(q.empty()==false)
           q.pop();
           else break;
       }
       int c=0;
       if(q.empty()==false)
       {
           while(!q.empty())
           {
               c+=q.top();
               q.pop();
           }
           cout<<c<<endl;
       }
       else cout<<c<<endl;
   
}
