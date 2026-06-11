
#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15

 int main(){

  long long l,r,cnt=0,i;
  cin>>l>>r;
 //cin>>i;

   for(int i=l;i<=r;i++){

     long long new0 = i,fact=1,result=0;
     vector<int>ans(0);

     while(new0){
        int rem = new0%10;
        ans.push_back(rem);
        new0 = new0/10;
     }

     vector<int>::iterator it;
       reverse(ans.begin(),ans.end());

     for(it = ans.begin();it!=ans.end();it++){
         result +=  *it*(fact);
        fact = fact*10;
     }

     if(result == i)
        cnt++;
  }

   cout<<cnt<<endl;


 return 0;
 }
