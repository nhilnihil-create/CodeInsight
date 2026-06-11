#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdint>

using namespace std;

unsigned long long int magicfunc(unsigned long long int *a,unsigned long long int n){
    
    unsigned long long int sum=a[0],xsum=a[0],ans=0;
    
    unsigned long long int l=0,r=0;
    
    while(l<n){
        while((sum+a[r+1])==(xsum^a[r+1])&&r+1<n){
            r++;
            sum+=a[r];
            xsum^=a[r];
        }
        ans+=r+1-l;
        cerr<<l<<" "<<r<<endl;
        sum-=a[l];
        xsum^=a[l];
        l++;
    }
    
    return ans;
    
}

int main(int argc , char **argv){
    
    unsigned int n; cin>>n;
    
    unsigned long long int a[n];
    for(unsigned int i=0;i<n;i++)cin>>a[i];
    cout<<magicfunc(a,n)<<endl;
    
    
    return 0;
    
}
