#include <bits/stdc++.h>
using namespace std;
#define pi 2*asin(1.0)


//template functions
/////////////////////////
long Comb(long N,long M){// nCm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
for(long i=M;i>0;i--){
    ans=ans/i;
}
return ans;
}
long Perm(long N,long M){// nPm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
return ans;
}
long GCM(long A,long B){
            long W,r;
    if(A<B){
        W=B;
        B=A;
        A=W;
    }
    while(A%B!=0){
        r=A%B;
        A=B;
        B=r;
    }
    return B;
}
long LCM(long A,long B){
    return (A*B)/GCM(A,B);
}
/////////////////////////


//Answer


int main() {

long X,Y,count=0;
cin>>X>>Y;
while(X<=Y){
X=X*2;
count++;
}
cout<<count<<endl;

}









//高精度要求→しつこくlong doubleでcast　出力はprintf("20.20Lf")とかで
//printf("%a.bLf")のとき、a-b-1が整数部分の桁数。
/*配列系の書き方
long N;
cin>>N;
vector<long> p(N);
for(long i=0;i<N;i++){
cin>>p.at(i);
}

vector<int> d(102,1);

sort(A.begin(),A.end());
reverse(A.begin(),A.end());

typedef pair<long,long> P;
vector<P> p(N);

*/