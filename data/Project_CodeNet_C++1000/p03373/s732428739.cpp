#include <bits/stdc++.h>

using namespace std;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int a,b,c,x,y,ans;
cin>>a>>b>>c>>x>>y;
int com=min(x,y);
int price1=min(com*(2*c),com*(a+b));
int price2=min(2*c*(x+y-2*com),a*(x-com)+b*(y-com));

cout<<price1+price2<<endl;

//system("pause");
return 0;
}