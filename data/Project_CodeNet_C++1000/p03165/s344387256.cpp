#include<bits/stdc++.h>
#define ll long long
using namespace std;

void lcs( string X, string Y, ll m, ll n )  
{  
    ll L[m + 1][n + 1];  
    
    memset(L,0,sizeof(L));
      
    
    for (ll i = 1; i <= m; i++)  
    {  
        for (ll j = 1; j <= n; j++)  
        {  
      
        if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    ll ind= L[m][n];  
    
    char A[ind+1];
    A[ind]='\0';
    
    int i = m, j = n; 
    
    while (i >= 0 && j >= 0) 
    { 
	    if (X[i-1] == Y[j-1]) 
	    { 
		    A[ind-1] = X[i-1]; 
		    i--; j--; ind--;	 
	    } 

	    else if (L[i-1][j] > L[i][j-1]) 
		        i--; 
	    else  j--; 
    }
    
    cout << A; 

}  
  

int main()  
{  
    string X,Y;
    cin >>X;
    cin >>Y;  
      
    ll m = X.size();  
    ll n = Y.size();  
      
    lcs( X, Y, m, n );  
      
    return 0;  
}