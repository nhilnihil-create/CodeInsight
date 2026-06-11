#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M;
    cin >> N >>M;
    int R1=99999999;
    int L1=0;
for(int i=0;i<M;i++){
    int L;
    cin >>L;
    int R;
    cin >>R;
    if(R<L){
        int a;
        a=L;
       L=R;
       L=a;
    }
    L1=max(L1,L);
    R1=min(R1,R);
}
int count=0;
for(int i=1;i<=N;i++){
    if(i<=R1&&L1<=i){
     count ++;
    }
}
cout << count <<endl;
}