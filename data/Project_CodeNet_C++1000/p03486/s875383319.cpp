#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
   	#endif
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    cout<<((s<t)?"Yes":"No");
   	return 0;
}