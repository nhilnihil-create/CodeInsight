#include <bits/stdc++.h>

using namespace std;

int main() {
        int n,a,b,c,d;
        cin >> n >> a >> b >> c >> d;
        string s;
        cin >> s;
        int temp = 0;
        
        if(c < d){
         for(int i=a-1;i<d-1;i++){
             if(s[i]==s[i+1]&&s[i]=='#'){temp=1;break;}
             
         }
            if(temp)cout <<"No";
            else cout <<"Yes";
            
        }
        if(c > d){
           for(int i = b-1;i<d;i++){
               if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){
                    temp=1;break;}
           }  
          if(temp)cout<<"Yes";
          else cout <<"No";
            
        }
    
}