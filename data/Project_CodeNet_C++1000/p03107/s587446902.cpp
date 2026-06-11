#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

   string s;
   cin>>s;
   int n=s.length();
   vector<char> st;
   int ans=0;
   for(int i=0;i<n;i++){
        if(st.size()==0){
            st.push_back(s[i]);
        }
        else{
            if(s[i]==st[st.size()-1]){
                st.push_back(s[i]);
            }
            else{
                ans+=2;
                st.pop_back();
            }
        }
   }
   cout<<ans;


return 0;
}
