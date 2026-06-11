        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  998244353;

     signed main(){
      
      int n,q;
      cin>>n>>q;
      string s;
      cin>>s;
      char t[q],d[q];
      for(int i=0;i<q;i++)cin>>t[i]>>d[i];
      int ng=-1,ok=n,mid;
      while(abs(ok-ng)>1){
           mid=(ok+ng)/2;
           for(int i=0;i<q&&mid!=-1&&mid!=n;i++){
                if(t[i]==s[mid]){
                     if(d[i]=='L')mid--;
                     else mid++;
                }
           }
           if(mid==n)ok=(ok+ng)/2;
           else ng=(ok+ng)/2;
      }
      int ans=ok;
      ng=-1;ok=n;
      while(abs(ok-ng)>1){
           mid=(ok+ng)/2;
           for(int i=0;i<q&&mid!=-1&&mid!=n;i++){
                if(t[i]==s[mid]){
                     if(d[i]=='L')mid--;
                     else mid++;
                }
           }
           if(mid==-1)ng=(ok+ng)/2;
           else ok=(ok+ng)/2;
      }
      cout<<ans-ok<<endl;


      }

        
