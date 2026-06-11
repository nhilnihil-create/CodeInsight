#include<bits/stdc++.h>
using namespace std;

long long inputs[200005];
long long oddsum[200005];
long long evensum[200005];

int main(){
   int n,m,x;
   cin >> n ;
   int ara[n+10];
   vector<int>vec;
   for(int i=1; i<=n; i++)
   {
       cin >> ara[i];
       vec.push_back(ara[i]);
   }
   sort(vec.begin(),vec.end());
   int fst = vec[n/2],sec = vec[n/2 -1];
   //cout << fst << " " << sec << endl;

   for(int i=1; i<=n; i++)
   {
       int val = ara[i];
       int l = 0 , r = n-1,pos;
       while(l<=r)
       {
           int mid = (l+r)/2;
           if(val>vec[mid])
           {
               l = mid+1;
           }
           else if(val<vec[mid])
           {
               r = mid - 1;
           }
           else
           {
               pos = mid+1;
               break;
           }
       }
     //  cout << val << " " ;
       //cout << pos << endl;
       if(pos<=n/2)
        cout << fst << endl;
       else cout << sec << endl;

   }


}
