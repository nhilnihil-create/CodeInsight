#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
 
#define rep(i,n) for(int i=0;i<(n);++i)

int upper_Bound(ll A[],int N,ll key){
    int left=-1;
    int right=N;
    int mid;
    while(right-left>1){
        mid=(left+right)/2;
        if(A[mid]<key){
            left=mid;
        }else{
            right=mid;
        }
        
       // cout<<"upper left:"<<left<<":"<<A[left]<<" right:"<<right<<":"<<A[right]<<endl;
    }
    return left;
}

int lower_Bound(ll A[],int N,ll key){
    int left=-1;
    int right=N;
    int mid;
    while(right-left>1){
        mid=(left+right)/2;
        if(key<A[mid]){
            right=mid;
        }else{
            left=mid;
        }
       // cout<<"lower left:"<<left<<":"<<A[left]<<" right:"<<right<<":"<<A[right]<<endl;
    }
    return right;
}


int main(){
  /*
    ll arr1[]={2,3,3,3,5,6};
   
    ll a=upper_Bound(arr1,6,3);
    cout<<a<<endl;

    ll b=lower_Bound(arr1,6,3);
    cout<<b<<endl;
    cout<<(a+1)*(3-b);
    */
   
    int N;
    cin>>N;
    
    ll A[N];
    rep(i,N){
        cin>>A[i];
    }
    sort(A,A+N);
    
    ll B[N];
    rep(i,N){
        cin>>B[i];
    }
    sort(B,B+N);
    
    ll C[N];
    rep(i,N){
        cin>>C[i];
    }
    sort(C,C+N);
    
    ll a,c;
    
    ll count=0;
    
    rep(i,N){
        a=upper_Bound(A,N,B[i]);
        c=lower_Bound(C,N,B[i]);
        count+=(a+1)*(N-c);
    }
    
    cout<<count<<endl;
    
}

