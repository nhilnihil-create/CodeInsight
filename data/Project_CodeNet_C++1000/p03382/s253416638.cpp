#include <iostream>
#include<math.h>
#include<algorithm>
typedef long long int ll;
using namespace std;

#define MAX 100005
 

int main(){
	int n,ans;
    ll mini=100000000000;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int k=a[n-1];
    for(int i=0;i<n;i++){
        if(mini>labs(a[i]*2-a[n-1])){
            mini=labs(a[i]*2-a[n-1]);
            ans=i;
        }
    }

    cout<<k<<" "<<a[ans]<<endl;
}