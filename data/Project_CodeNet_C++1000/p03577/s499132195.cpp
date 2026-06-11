#include<bits/stdc++.h>
#define at putchar('\n')
using namespace std;
int main(void)
{
	string s;
	cin>>s;
	for(int i=1;i<=8&&!s.empty();i++) s.erase(--s.end());
	cout<<s;
	at;
    return 0;
}