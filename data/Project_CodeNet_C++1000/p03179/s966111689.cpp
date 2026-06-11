#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
const int N = 3e3+10;

vector<int> cur(N),nex(N);

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
   int n;
    cin >> n;
    
   string s;
    cin >> s;
    
   
   for(int i=1;i<=n;i++) cur[i] = 1;
    
   for(int i=0;i<n-1;i++)
   {
       if(s[i] == '<')
           for(int j=1;j<=i+2;j++) nex[j] = (nex[j-1] + cur[j-1])%MOD; 
       else
           for(int j=1;j<=i+2;j++) nex[j] = ( (nex[j-1] + cur[i+2] - cur[j-1])%MOD +MOD)%MOD;
       
       nex[i+3] = nex[i+2];
       
       swap(cur,nex);
   }
    
   cout << cur[n]; 
}