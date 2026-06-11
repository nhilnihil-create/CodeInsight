#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string.h>

using namespace std;

typedef long long ll;

char s[200010];
char t[200010];


int main(){
    //string s,t;
    cin>>s>>t;
    
    vector<int> alphs(26,0);
    vector<int> alpht(26,0);
    
    
    
    size_t ls=strlen(s);
    size_t lt=strlen(t);
    vector<int> vecs(ls,0);
    vector<int> vect(lt,0);
    
    
    int counts=0;
    for(int i=0;i<ls;++i){
        if(alphs[s[i]-'a']==0){
            alphs[s[i]-'a']=counts;
            ++counts;
        }
        vecs[i]=alphs[s[i]-'a'];
    }
    
    int countt=0;
    
    bool ans=true;
    
    for(int i=0;i<lt;++i){
        if(alpht[t[i]-'a']==0){
           ++alpht[t[i]-'a']=countt;
            ++countt;
        }
        vect[i]=alpht[t[i]-'a'];
        
        if(vecs[i]!=vect[i]){
            ans=false;
            break;
        }
        
    }
    
  
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
    
   

    
    
}
