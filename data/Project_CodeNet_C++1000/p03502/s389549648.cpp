#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
   	#endif
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();++i) sum+=s[i]-'0';
    int x=stoi(s);
	cout<<((x%sum==0)?"Yes":"No");
   return 0;
}