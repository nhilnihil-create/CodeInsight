#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,ans=0,p;
	cin>>a>>b>>c;
	if(a==b&&b==c){
		cout<<0;
		return 0;
	}
	while(1){
		if(a%2==b%2&&b%2==c%2){
			p=min(a,min(b,c));
			if(a==p){
				a+=2;
			}
			else if(b==p){
				b+=2;
			}
			else{
				c+=2;
			}
			ans++;
		}
		else if(a%2!=b%2&&a%2!=c%2){
			b++;
			c++;
			ans++;
		}
		else if(b%2!=a%2&&b%2!=c%2){
			a++;
			c++;
			ans++;
		}
		else if(c%2!=a%2&&c%2!=b%2){
			a++;
			b++;
			ans++;
		}
		if(a==b&&b==c){
			break;
		}
	}
	cout<<ans;
	return 0;
}