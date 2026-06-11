#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin>>N;
vector<int>V(N);
vector<int>P(N);
for(int i=0;i<N;i++){
    cin>>V[i];
}
for(int i=0;i<N;i++){
    cin>>P[i];
}

int sum=0;
for(int i=0;i<N;i++){
    if(V[i]-P[i]>0){
        sum+=V[i]-P[i];
    }
}
cout<<sum<<endl;
}