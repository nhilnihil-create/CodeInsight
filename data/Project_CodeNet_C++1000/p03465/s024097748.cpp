#include<bits/stdc++.h>
using namespace std;int n,x,tot;bitset<4000010> bs;
int main(){cin>>n,bs[0]=1;while(n--){cin>>x;tot+=x;bs|=(bs<<x);}for(int i=(tot+1)/2;;i++){if(bs[i]==1){cout<<i<<endl;return 0;}}return 0;}
