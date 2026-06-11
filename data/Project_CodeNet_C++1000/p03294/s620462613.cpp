#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
int N;
cin>>N;
for(int i=0;i<N;i++){
    cin>>a[i];
}
int s=0;
for(int i=0;i<N;i++){
    s+=a[i];
}
int ans=s-N;
cout<<ans<<endl;
   return 0;

}

