#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);  
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);  
       cin.tie(NULL);
       /*
       ll n , cnt = 0;
       cin>>n;
       ll a[n];  
       for (int i = 0; i < n; ++i)
       {
       	 cin>>a[i];
       }
       for (int i = 0; i < n - 2; ++i)
       {
       	 if(a[i] != a[i+2]){
       	 	cnt++;
       	 }
       }  
       cout<<cnt<<endl;  
       return 0;
   }
   _______________________________Main_______________

int n ,k;  
cin>>n>>k;
int i = 0 , j = 0 , l= 0;
int cnt = 0;
for (i = 1; i <= n; i++) 
        { 
            for (j = 1; j <= n; j++) 
            { 
                for (l = 1; l <= n; l++) 
                { 
  
                     
 if ((i + j) % k == 0 && (i + l) % k == 0 && (j + l) % k == 0) 
                        cnt++; 
                 
            } 
        } 
}
cout<<cnt<<endl;
}

*/

ll n;  
cin>>n ;
ll a[n];       
ll cnt = 0;
for (int i = 0; i <n; ++i)   
{
	cin>>a[i];
	a[i] -= (i + 1);
}  
sort(a, a+n);
for (int i = 0; i < n; ++i)  
{
	cnt += abs(a[i] - (a[n/2]));
}
cout<<cnt<<endl;
return 0;
}  