#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[10002];
int N;
cin>>N;
for(int i=0;i<N;i++){
        cin>>A[i];

}
int mx=A[0];
int mn=A[0];
for(int i=0;i<N;i++){
        if(A[i]>mx)mx=A[i];
        if(A[i]<mn)mn=A[i];
}
cout<<mx-mn;
return 0;
}
