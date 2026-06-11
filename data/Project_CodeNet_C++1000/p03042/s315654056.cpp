#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int a=(s[0]%48);
	int b=(a*10)+(s[1]%48);
	int c=((s[2]%48)*10)+(s[3]%48);
	
	 if(((b>=1)&&(b<=12))&&((c>=1)&&(c<=12)))
    {
        cout<<"AMBIGUOUS";
    }
    else if((b>=1)&&(b<=12))
        {
            cout<<"MMYY";
        }
    else if((c>=1)&&(c<=12))

        {
            cout<<"YYMM";
        }
        else
        {
            cout<<"NA";
        }
}