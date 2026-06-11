#include<bits/stdc++.h>
using namespace std;
int main()
{
int A,B,ans=0;
cin>>A>>B;
ans = max(ans,A+A-1);
ans = max(ans,A+B);
ans = max(ans,B+B-1);
cout<<ans<<endl;
return 0;
}
