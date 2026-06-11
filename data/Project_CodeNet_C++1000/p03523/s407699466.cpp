#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,m;
  cin>>s;
 int count=0;
 bool check=true;
     for(int i=0;i<s.size();i++){
         if(i>0&&s.at(i)=='A'&&s.at(i-1)=='A'){check=false;break;}
         if(i>0&&i<s.size()-1&&(s.at(i-1)=='K'&&s.at(i)=='A'&&s.at(i+1)=='I'||s.at(i-1)=='I'&&s.at(i)=='A'&&s.at(i+1)=='H')){check=false;break;}
         if(s.at(i)=='A')count++;
         else m.push_back(s.at(i));
     }
     if(count>5||m.size()!=5||m.at(0)!='K'||m.at(1)!='I'||m.at(2)!='H'||m.at(3)!='B'||m.at(4)!='R')check=false;
  if(check)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
}