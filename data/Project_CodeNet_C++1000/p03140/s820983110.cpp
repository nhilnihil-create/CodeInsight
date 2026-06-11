#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
  int n;cin>>n;
  string a, b, c;cin>>a>>b>>c;
  int ans=0;
  for(int i=0;i<n;i++){
    int num=0;
  	if(a[i]==b[i])num++;
    if(a[i]==c[i])num++;
    if(b[i]==c[i])num++;
    if(num==3)ans+=0;
    else if(num==1)ans+=1;
    else ans+=2;
  }
  cout<<ans<<endl;
}
