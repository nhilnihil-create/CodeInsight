        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

   int m[(1<<('z'-'a' +1))];
vector<pair<int,int>> k;
        signed main() {
     string s;
     cin>>s;
     vector<int> hen[s.size()];
     int sc[s.size()+1],b=0;
  
     for(int i=0;i<s.size();i++){
             sc[i]=b;
           
             b^=1<<(s[i]-'a');
             
     }
       m[b]=s.size();
     for(int i=s.size()-1;i>=0;i--){
             for(int j=0;j<='z'-'a';j++){
                  
                     if(m[sc[i]^(1<<j)]!=0)hen[i].push_back(m[sc[i]^(1<<j)]);
             }
             m[sc[i]]=i;
     }

     queue<int> que,que2;
     int c=0;
     que.push(0);
     while(true){
             if(que.empty()){
                     swap(que,que2);
                     c++;
             }
             if(que.front()==s.size()||sc[que.front()]==b){
                     cout<<max(1ll,c);
                     return 0;
             }
             if(sc[que.front()]==-1){
                     que.pop();
                     continue;
             }
             //cerr<<que.front()<<' '<<c<<endl;
             sc[que.front()]=-1;
             for(int i=0;i<hen[que.front()].size();i++)que2.push(hen[que.front()][i]);
             que.pop();
     }

      
        


      }


        
