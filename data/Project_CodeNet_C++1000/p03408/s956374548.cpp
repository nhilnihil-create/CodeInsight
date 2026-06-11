#include <bits/stdc++.h>
using namespace std;
int main(){
  vector <vector <string>>vec(2);
  int n,m,counter,ans=0;
  string strin;
  
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>strin;
    vec.at(0).push_back(strin);
  }
  cin>>m;
  for (int k=0;k<m;k++){
    cin>>strin;
    vec.at(1).push_back(strin);
  }
  string st;
  for(int l=0;l<2;l++){
    for(string str:vec.at(l)){    
      st=str;
      counter=0;
      for(int o=0;o<2;o++){
    	for(string tr:vec.at(o)){
        
          if(tr==st){
            if(o==0)
              counter++;
            else if (o==1)
              counter--;
          }   
          else
            continue;
        }        
      }
    if(ans<counter)
            ans=counter;
          else
            continue;    
    }

  }
  cout<<ans<<endl;
  }

      