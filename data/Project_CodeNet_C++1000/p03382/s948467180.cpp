#include<bits/stdc++.h>
#define mx 1e10
using namespace std ;
int arr[100001] ;
//int res[100001] ;

int main(){
   // freopen("in.txt","r",stdin) ;
int n ;scanf("%d",&n) ;
for(int i=0 ; i<n ;i++){
    scanf("%d",&arr[i]) ;
}
sort(arr, arr+n) ;
/*for(int i=0 ; i<n ; i++){
    cout << arr[i] << " " ;

}*/
int a = arr[n-1] ;
int k  ; int mn = mx ;
for(int i=0 ; i<n-1 ; i++){
     if(abs(a-2*arr[i])< mn){
        k=arr[i] ;
        mn=abs(a-2*k) ;
       //printf("%d  %d\n",k,mn) ;
     }
}
printf("%d %d",a,k) ;




return 0 ;
}
