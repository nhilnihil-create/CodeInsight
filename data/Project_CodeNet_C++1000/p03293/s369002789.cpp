        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

     signed main(){
string s,t;
cin>>s>>t;
for(int i=0;i<s.size();i++){
    bool k=true;
    for(int j=0;j<s.size();j++)if(s[j]!=t[(i+j)%s.size()]){
        k=false;
        break;
    }
    if(k){
        cout<<"Yes"<<endl;
        return 0;
    }

}
cout<<"No"<<endl;

     }


 


 






    





      

        
