#include<bits/stdc++.h>
using namespace std;
string s,st;
int x=1,len;
inline void write(long long x)    
{
    if (x<0)
    {
    	putchar('-');
    	x=-x;
	}
	if (x>9)
      write(x/10);
    putchar(x%10+'0');
}
int main()
{
    cin>>st;
    s=' '+st;
    len=st.size();
    if (s[1]=='0'||s[len]=='1')
	{
        write(-1);
        return 0;
    }
    for (register int i=1;i<len;++i)
      if (s[i]^s[len-i])
	  {
        write(-1);
        return 0;
      }
    for (register int i=2;i<=len;++i)
	{
        write(x);putchar(' ');
        write(i);putchar('\n');
        if (s[i-1]=='1')
		  x=i;
    }
    return 0;
}