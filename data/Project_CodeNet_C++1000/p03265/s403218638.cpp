//Ruined Square

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / __gcd(a, b) * b
#define range(a) (a).begin(),(a).end()
const int inf = 2147483647;

int main (){
    int x,y,xx,yy;cin>>x>>y>>xx>>yy;
    int Dx = xx-x,Dy = yy-y;
    cout << xx-Dy <<" "<< yy+Dx <<" "<< x-Dy <<" "<< y+Dx << endl;
    return 0;
}