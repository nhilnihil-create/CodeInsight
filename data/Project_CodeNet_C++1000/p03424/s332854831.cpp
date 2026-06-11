#include <bits/stdc++.h> 
#define ll long long int 
using namespace std; 
  
int main() 
{  
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);  
    int n;
     cin>>n;
    std::set<char >s; 
    for(int i=0;i<n;i++)  
    {
        char x; 
        cin>>x; 
        s.insert(x); 
    } 
    if(s.size()==3)  cout<<"Three"; 
    else 
         cout<<"Four";
    return 0; 
} 
