        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 200004;
const int MOD =998244353
 ;
const int INV2 = (MOD+1)/2;
int k,x,y;


     signed main(){
         string s,t;int a[('z'-'a')+1]={},b[('z'-'a')+1]={};
         cin>>s>>t;
         for(int i=0;i<s.size();i++)a[s[i]-'a']++;
         for(int i=0;i<t.size();i++)b[t[i]-'a']++;
         sort(a,a+('z'-'a')+1);sort(b,b+('z'-'a')+1);
         for(int i=0;i<('z'-'a')+1;i++)if(a[i]!=b[i]){
              cout<<"No"<<endl;
              return 0;
         }
         cout<<"Yes"<<endl;
         return 0;


}


        
