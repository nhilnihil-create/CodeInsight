        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;


     signed main(){
         cout << std::fixed << std::setprecision(15);
int a,b,k;
cin>>a>>b>>k;
for(int i=0;i<k;i++){
     if(a%2)a--;
     a/=2;b+=a;
     swap(a,b);
}
if(k%2)cout<<b<<' '<<a;
else cout<<a<<' '<<b;
cout<<endl;
     }

 


 






    





      

        
