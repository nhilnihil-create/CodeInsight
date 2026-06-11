#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  	map<int,int >count;
  for(int i=0,a;i<n;i++){cin>>a;count[a]+=1;}
  int m;cin>>m;
  int pos=1;
  for(int i=0,a;i<m;i++){cin>>a;
                      if(pos==0)continue;
     if(count.find(a)==count.end()){pos=0;continue;} 
     if(count[a]==0){pos=0;continue;}
                         else count[a]-=1;
                        }
 if(pos==1)cout<<"YES";
  else cout<<"NO";
}