//RGB Boxes

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / __gcd(a, b) * b
#define range(a) (a).begin(),(a).end()
const int inf = 2147483647;

int main (){
    int R,G,B,N,Ans=0;cin>>R>>G>>B>>N;
    for(int i=0;i*R<=N;i++){
        for(int j=0;(j*G+i*R)<=N;j++){
            if(N>=i*R+j*G&&(N-i*R-j*G)%B==0)Ans++;
        }
    }
    cout << Ans << endl;
    return 0;
}