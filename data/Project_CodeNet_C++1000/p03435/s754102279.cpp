#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int A,B,C,D,E,F,G,H,I;
    cin>>A>>B>>C>>D>>E>>F>>G>>H>>I;
    bool ans=true;
    if(B-A==E-D&&E-D==H-G){
    }
    else{
        ans=false;
    }
    if(C-B==F-E&&F-E==I-H){
    }
    else{
        ans=false;
    }
    if(D-A==E-B&&E-B==F-C){
    }
    else{
        ans=false;
    }
    if(G-D==H-E&&H-E==I-F){
       
    }
  else{
    ans=false;
  }
    if(ans==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}