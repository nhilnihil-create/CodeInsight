#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
 int n,m;
 cin >> n >> m;
 char mat[n+10][m+10];
 for(int i=0; i<n; i++)
 {
     for(int j=0; j<m; j++)
     {
         cin >> mat[i][j];
     }
 }
 bool ok = 0;

 for(int i=0; i<n; i++)
 {
     for(int j=0; j<m; j++)
     {
         if(mat[i][j]=='#')
         {
             if(i>0 && mat[i-1][j]=='#')continue;
             if(i<n-1 && mat[i+1][j]=='#')continue;
             if(j>0 && mat[i][j-1]=='#')continue;
             if(j<m-1 && mat[i][j+1]=='#')continue;
             ok=1;break;
         }
     }
 }

 if(!ok)cout << "Yes" << endl;
 else cout << "No" << endl;


}
