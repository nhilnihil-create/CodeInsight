#include <bits/stdc++.h>
using namespace std;






int main(){

  

  int n,m;
  cin>>n>>m;
  
  vector<vector<pair<int,int>>> data(n+1,vector<pair<int,int>>(0));
  
  for (int i=1;i<=m;i++){
    int p,y;
    cin>>p>>y;
    
    pair<int,int> tmp=make_pair(y,i);
    
    data.at(p).push_back(tmp);
  }
  
  for (int i=1;i<=n;i++){
    sort(data.at(i).begin(),data.at(i).end());
  }


  
  
  vector<string> answer(m+1);
  
  for (int i=1;i<=n;i++){
    int provsize=int(data.at(i).size());
    
    for (int j=0;j<provsize;j++){
      
      string formerstring="";
      string latterstring="";
      
      string formernumber=to_string(i);
      string latternumber=to_string(j+1);
      
      
      for (int k=0;k<(6-int(formernumber.size()));k++){
        formerstring+="0";
      }
      formerstring+=formernumber;
      for (int k=0;k<(6-int(latternumber.size()));k++){
        latterstring+="0";
      }
      latterstring+=latternumber;
      

      
      answer.at(data.at(i).at(j).second)=(formerstring+latterstring);
      
    }
  }
  
  for (int i=1;i<=m;i++){
    cout<<answer.at(i)<<endl;
  }
  


  
}
