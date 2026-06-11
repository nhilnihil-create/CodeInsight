#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cin>>s;
	unsigned int n,i,j,length=0; //HAGATAYA
	n = strlen(s.c_str());
    
    for(i=0;i<n;i++)
    {
    	if(s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C')
    	{
    	  j=1;
          i++;

          while((s[i]=='A'||s[i]=='T'||s[i]=='G'||s[i]=='C')&&i<n)
          {
          	
          	i++;
          	j++;
          }

          length = max(length,j); 
    	}
    	
    }
    cout<<'\n'<<length;


}