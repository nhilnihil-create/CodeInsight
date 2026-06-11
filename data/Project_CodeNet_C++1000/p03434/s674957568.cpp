#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
        cin >> a[i];
    
    int alice=0,bob=0;
    sort(a,a+n);
    int j=0,k=1;
    if(n%2==0){
        while(j<=n-1){
            bob += a[j];
            j += 2;
        }
        while(k<=n-1){
            alice += a[k];
            k += 2;
        }
        
    }else{
        while(j<=n-1){
            alice += a[j];
            j += 2;
        }
        while(k<=n-1){
            bob += a[k];
            k += 2;
        }
    }
    cout << alice - bob << endl;
}  
