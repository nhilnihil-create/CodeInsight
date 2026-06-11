#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B,C;
cin>>A>>B>>C;
int n=max(A,B);
int k=max(n,C);
cout<<A+B+C+k*9<<endl;
}
