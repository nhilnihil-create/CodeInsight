#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;
  for(long n=1;n<=3500;n++)for(long w=1;w<=3500;w++){
    long a=N*n*w,b=4*n*w-N*n-N*w;
    if(b>0&&a%b==0){cout<<a/b<<" "<<n<<" "<<w;return 0;}
  }
}