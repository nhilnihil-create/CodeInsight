#include <bits/stdc++.h>
using namespace std;
int main(){
int A,B;
cin>>A>>B;
int answer=max(A+B,A-B);
answer=max(answer,A*B);
cout<<answer<<endl;
}
