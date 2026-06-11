#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int min(int a,int b){
	return (a>b?b:a);
}

int go(int *a,int n){
    int f=0;
    if(n==1) return f;
    int s=abs(a[0]-a[1]);
    if(n==2) return s;
    int c=INT_MAX;
    for(int i=2;i<n;i++){
        c=min(s+abs(a[i]-a[i-1]),f+abs(a[i]-a[i-2]));
        f=s;
        s=c;
    }
    return c;
}
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<go(a,n)<<endl;
 return 0; 
}

