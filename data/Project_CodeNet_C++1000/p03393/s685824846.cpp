//uvwzyx
//uvwyzx
#include<bits/stdc++.h>
using namespace std;
int main(){
string s;cin>>s;
//if atleast is not there, then it is easy
  vector<int >nos(26,-1);
  for(int i=0;i<s.size();i++){
  	nos[s[i]-'a']=i;
  }
  //if anything is -1
  int repl=-1;
  for(int i=0;i<26;i++)if(nos[i]==-1){repl=i;break;}
  if(repl!=-1){cout<<s;cout<<(char)('a'+repl);}
  else{
  	for(int i=s.size()-1;i>0;i--){
    	if(s[i]>s[i-1]){
        	//swapping has to work
          	
            	//something special
              for(int j=0;j<i-1;j++)cout<<s[j];
              repl=-1;
              for(int j=0;j<26;j++){
              	if(('a'+j > s[i-1] ) && nos[j]>=i){repl=j;break;}
              }
              if(repl==-1)break;
              cout<<(char)('a'+repl);
              return 0;
            }
          
    }
    cout<<-1;
  }
}
